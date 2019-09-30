#include "includes.h"

void setup() {
  // Set up serial connection
  Serial.begin(SERIAL_BAUDRATE);
  Serial.setTimeout(SERIAL_TIMEOUT);

  delay(1000);

  /** LED info is contained in variables.h

  Useful static variables:
    - NUM_LEDS_FACE_{ONE,TWO,THREE,FOUR,FIVE,SIX}
    - NUM_LEDS_FACE_{ONE,TWO,THREE,FOUR,FIVE,SIX}_SIDE_{ONE,TWO,THREE,FOUR}
    - FACE_{ONE,TWO,THREE,FOUR,FIVE,SIX}_SIDE_{ONE,TWO,THREE,FOUR,FIVE,SIX}_{START,END}
    - NUM_LEDS_MAX
    _ NUM_LEDS_MIN

  **/


  // -- Six strips of LEDS, each nominally 240 leds (but slightly less) -------------------- //
	FastLED.addLeds<LED_TYPE, LED_PIN_ONE, COLOR_ORDER>(leds_face_one, NUM_LEDS_FACE_ONE);
  FastLED.addLeds<LED_TYPE, LED_PIN_TWO, COLOR_ORDER>(leds_face_two, NUM_LEDS_FACE_TWO);
	FastLED.addLeds<LED_TYPE, LED_PIN_THREE, COLOR_ORDER>(leds_face_three, NUM_LEDS_FACE_THREE);
	FastLED.addLeds<LED_TYPE, LED_PIN_FOUR, COLOR_ORDER>(leds_face_four, NUM_LEDS_FACE_FOUR);
	FastLED.addLeds<LED_TYPE, LED_PIN_FIVE, COLOR_ORDER>(leds_face_five, NUM_LEDS_FACE_FIVE);
	FastLED.addLeds<LED_TYPE, LED_PIN_SIX, COLOR_ORDER>(leds_face_six, NUM_LEDS_FACE_SIX);
  // --------------------------------------------------------------------------------------- //

  // Set up variables
  random16_set_seed(4832);
  random16_add_entropy(analogRead(2));

  Serial.println("---SETUP COMPLETE---");

  // Load starting mode and number of leds
  led_mode = STARTMODE;

  // Set up circ_noise variables
  for (long i = 0; i < NUM_LEDS_MIN; i++) {
    uint8_t angle = (i * 256) / NUM_LEDS_MIN;
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
  if(glitter) { addglitter(10); }

  // Update all strips
  FastLED.show();
}

/*
 * Sets the mode/routine for the LEDs.
 *
 * @param newMode : the mode to set the leds to
 * @param mc      : signifies if we're changing modes or not
 */
void strobe_mode(uint8_t newMode, bool mc){

  // If this_ is a *new* mode, clear out LED array.
  if(mc) {
    clear_all();
    Serial.print("Mode: ");
    Serial.println(led_mode);
    FastLED.show();
  }

  switch (newMode) {

    // 0 - all off
    case 0:
      if(mc) { clear_all(); }
      break;

    // 1 - all on, white
    case 1:
      if(mc) { this_sat=0; this_bright=255; fill_solid_all(); }
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

      // Command: a {hue} - set all strips to {hue} (0-255)
      case 97:
        led_mode = 0;
        this_hue = Serial.parseInt();
        this_hue = constrain(this_arg, 0, 255);
        Serial.println(this_arg);
        fill_solid_all();
        break;

      // Command: b {brightness} - set strips to {brightness} (0-255)
      case 98:
        max_bright = Serial.parseInt();
        max_bright = constrain(max_bright, 0, 255);
        Serial.println(max_bright);
        FastLED.setBrightness(max_bright);
        break;

      // Command: c - clear all strips
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

      // Command: m {mode} - select mode {mode} (0-255)
      case 109:
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

      // Command: s {saturation} - set saturation to {saturation} (0-255)
      case 115:
        this_arg = Serial.parseInt();
        this_sat = constrain(this_arg, 0, 255);
        Serial.println(this_sat);
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
