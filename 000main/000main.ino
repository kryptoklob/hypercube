#include "includes.h"

void setup() {
  // Set up serial connection
  Serial.begin(SERIAL_BAUDRATE);
  Serial.setTimeout(SERIAL_TIMEOUT);

  delay(1000);

  // -- Six strips of LEDS, each nominally 240 leds (but slightly less) -------------------- //
	FastLED.addLeds<LED_TYPE, LED_PIN_ONE, COLOR_ORDER>(leds, NUM_LEDS_FACE_ONE);
  FastLED.addLeds<LED_TYPE, LED_PIN_TWO, COLOR_ORDER>(leds, NUM_LEDS_FACE_TWO);
	FastLED.addLeds<LED_TYPE, LED_PIN_THREE, COLOR_ORDER>(leds, NUM_LEDS_FACE_THREE);
	FastLED.addLeds<LED_TYPE, LED_PIN_FOUR, COLOR_ORDER>(leds, NUM_LEDS_FACE_FOUR);
	FastLED.addLeds<LED_TYPE, LED_PIN_FIVE, COLOR_ORDER>(leds, NUM_LEDS_FACE_FIVE);
	FastLED.addLeds<LED_TYPE, LED_PIN_SIX, COLOR_ORDER>(leds, NUM_LEDS_FACE_SIX);
  // --------------------------------------------------------------------------------------- //

  // Set up variables
  random16_set_seed(4832);
  random16_add_entropy(analogRead(2));

  Serial.println("---SETUP COMPLETE---");

  // Load starting mode and number of leds
  led_mode = STARTMODE;

  // Set up circ_noise variables
  for (long i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    uint8_t angle = (i * 256) / NUM_LEDS_PER_STRIP;
    xd[i] = cos8( angle );
    yd[i] = sin8( angle );
  }

  // Init first mode
  strobe_mode(led_mode, STARTMODE);
}

void loop() {
  // Get keyboard input
  readkeyboard();

  // Dynamically change delay
  EVERY_N_MILLIS_I(this_timer, this_delay) {
    this_timer.setPeriod(this_delay);
    strobe_mode(led_mode, 0);
  }

  // Optionally add glitter
  if(glitter) addglitter(10);

  if (led_mode > 5) { FastLED.show(); }
}

/*
 * Sets the mode/routine for the LEDs.
 *
 * @param newMode : the mode to set the leds to
 * @param mc      : signifies if we're changing modes or not
 */
void strobe_mode(uint8_t newMode, bool mc){

  // If this_ is a *new* mode, clear out LED array.
  if(mc && newMode != 2) {
    fill_solid(leds, NUM_LEDS_PER_STRIP, CRGB( 0, 0, 0));
    Serial.print("Mode: ");
    Serial.println(led_mode);
    FastLED.show();
  }

  switch (newMode) {

    // 0 - all off
    case 0:
      if(mc) { fill_solid(leds, NUM_LEDS_PER_STRIP, CRGB( 0, 0, 0 )); }
      break;

    // 1 - all on, white
    case 1:
      if(mc) { fill_solid(leds, NUM_LEDS_PER_STRIP, CRGB( 255, 255, 255 )); }
      break;

		// 2 - cube test 1
		case 2:
			cube_test();
			break;

		// 3 - cube test 2
		case 3:
			cube_test_parallel();
			break;

    // 4 - rainbow march with narrow waves
    case 4:
 			if(mc) { this_delay = 0; this_dir = 1; this_rot = 2; this_diff = 3; }
			rainbow_march();
			break;
  }
}

/*
 * Takes in keyboard input and executes commands.
 *
 * Serial timeout value here is important.
 * We should make sure it's set high enough
 * to type the entire command within the timeout.
 */
void readkeyboard() {
  while (Serial.available() > 0) {

    in_byte = Serial.read();

    // Don't print carriage return
    if (in_byte != 10) {
      Serial.print("# ");
      Serial.print(char(in_byte));
      Serial.print(" ");
    }

    switch(in_byte) {

      // Command: a {hue} - set entire strip to {hue} (0-255)
      case 97:
        led_mode = 0;
        this_arg = Serial.parseInt();
        this_arg = constrain(this_arg, 0, 255);
        Serial.println(this_arg);
        fill_solid(leds, NUM_LEDS_PER_STRIP, CHSV(this_arg, 255, 255));
        break;

      // Command: b {brightness} - set entire strip to {brightness} (0-255)
      case 98:
        max_bright = Serial.parseInt();
        max_bright = constrain(max_bright, 0, 255);
        Serial.println(max_bright);
        LEDS.setBrightness(max_bright);
        break;

      // Command: c - clear strip
      case 99:
        Serial.println(" ");
        led_mode = 0;
        strobe_mode(led_mode, 1);
        break;

      // Command: d {delay} - set the delay amount to {delay} (0-255)
      case 100:
        this_arg = Serial.parseInt();
        this_delay = constrain(this_arg, 0, 255);
        Serial.println(this_delay);
        break;

      // Command: e {0/1} - increment or decrement the mode
      case 101:
        this_arg = Serial.parseInt();
        if (this_arg) {
          demo_run = 0;
          led_mode = (led_mode + 1)%(max_mode + 1);
        } else {
          demo_run = 0;
          led_mode = (led_mode - 1);
          if (led_mode == 255) led_mode = max_mode;
        }
        strobe_mode(led_mode, 1);
        break;

      // Command: f {palette_number} - set the current palette
      case 102:
        demo_run = 0;
        palette_change = 0;
        this_arg = Serial.parseInt();
        g_current_palette_number = this_arg % g_gradient_palette_count;
        target_palette = g_gradient_palettes[g_current_palette_number];
        Serial.println(g_current_palette_number);
        break;

      // Command: g - toggle glitter
      case 103:
        glitter = !glitter;
        Serial.println(" ");
        break;

      // Command: h {hue} - set hue variable to {hue} (0-255)
      case 104:
        this_arg = Serial.parseInt();
        this_hue = constrain(this_arg, 0, 255);
        Serial.println(this_hue);
        break;

      // Command: i {hue} - set similar pallete with selected hue {hue} (0-255)
      case 105:
        palette_change = 0;
        this_arg = Serial.parseInt();
        this_hue = constrain(this_arg, 0, 255);
        Serial.println(this_hue);
        SetupMySimilar4Palette();
        break;

      // Command: m {mode} - select mode {mode} (0-255)
      case 109:
	old_mode = led_mode;
        led_mode = Serial.parseInt();
        led_mode = constrain(led_mode, 0, max_mode);
        Serial.println(led_mode);
        strobe_mode(led_mode, 1);
        break;

      // Command: n - toggle direction
      case 110:
        Serial.println(" ");
        this_dir = !this_dir;
        break;

      // Command: p {0/1/2} - set demo mode (fixed/sequential/shuffle)
      case 112:
        demo_run = Serial.parseInt();
        demo_run = constrain(demo_run, 0, 2);
        Serial.println(demo_run);
        break;

      // Command: s {saturation} - set saturation to {saturation} (0-255)
      case 115:
        this_arg = Serial.parseInt();
        this_sat = constrain(this_arg, 0, 255);
        Serial.println(this_sat);
        break;

      // Command: t {0/1/2/3} - set palette mode (fixed/4similar/random4/random16)
      case 116:
        this_arg = Serial.parseInt();
        palette_change = constrain(this_arg, 0, 3);
        Serial.println(palette_change);
        break;

      // Command: w - write current mode to EEPROM
      case 119:
        EEPROM.write(STARTMODE, led_mode);
        Serial.print("Writing keyboard: ");
        Serial.println(led_mode);
        break;
    }
  }
}
