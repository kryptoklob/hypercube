#ifndef CUBE_TEST_H
#define CUBE_TEST_H

/* Usage - cube_test(); */

void cube_test() {
	// Pulse the brightness
  // Every strip will be red, green, or blue

	if (this_dir == 0) { this_bright+=5; }
  if (this_dir == 1) { this_bright-=5; }
  if (this_bright >= 250) { this_dir = 1; }
  if (this_bright <= 5) { this_dir = 0; }

  fill_solid(leds_face_one, NUM_LEDS_FACE_ONE, CRGB::Red);
  fill_solid(leds_face_two, NUM_LEDS_FACE_TWO, CRGB::Blue);
  fill_solid(leds_face_three, NUM_LEDS_FACE_THREE, CRGB::Green);
  fill_solid(leds_face_four, NUM_LEDS_FACE_FOUR, CRGB::Red);
  fill_solid(leds_face_five, NUM_LEDS_FACE_FIVE, CRGB::Blue);
  fill_solid(leds_face_six, NUM_LEDS_FACE_SIX, CRGB::Green);

  FastLED.setBrightness(this_bright);
}

#endif
