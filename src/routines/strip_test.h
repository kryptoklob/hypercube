#ifndef STRIP_TEST_H
#define STRIP_TEST_H

/* Usage - strip_test(); */

void strip_test() {
	// Pulse the brightness
  // Every leds will be red, green, or blue

	if (this_dir == 0) { this_bright+=5; }
  if (this_dir == 1) { this_bright-=5; }
  if (this_bright >= max_bright-5) { this_dir = 1; }
  if (this_bright <= 5) { this_dir = 0; }

  fill_solid(leds_one, NUM_LEDS_FACE_ONE, CRGB::Red);
  fill_solid(leds_two, NUM_LEDS_FACE_TWO, CRGB::Blue);
  fill_solid(leds_three, NUM_LEDS_FACE_THREE, CRGB::Green);
  fill_solid(leds_four, NUM_LEDS_FACE_FOUR, CRGB::Red);
  fill_solid(leds_five, NUM_LEDS_FACE_FIVE, CRGB::Blue);

  FastLED.setBrightness(this_bright);
}

#endif
