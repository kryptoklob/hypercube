#ifndef CUBE_TEST_H
#define CUBE_TEST_H

/* Usage - cube_test(); */

void cube_test() {
	// Pulse the brightness
  
	if (this_dir == 0) { this_bright+=5; }
  if (this_dir == 1) { this_bright-=5; }
  if (this_bright >= 250) { this_dir = 1; }
  if (this_bright <= 5) { this_dir = 0; }


	// Strip 0 (pin 1)
	fill_solid(leds, NUM_LEDS_FACE_ONE, CRGB::Blue);
	FastLED[0].showLeds(this_bright);

	// Strip 1 (pin 2)
	fill_solid(leds, NUM_LEDS_FACE_TWO, CRGB::Green);
	FastLED[1].showLeds(this_bright);

	// Strip 2 (pin 3)
	fill_solid(leds, NUM_LEDS_FACE_THREE, CRGB::Red);
	FastLED[2].showLeds(this_bright);

	// Strip 3 (pin 4)
	fill_solid(leds, NUM_LEDS_FACE_FOUR, CRGB::Blue);
	FastLED[3].showLeds(this_bright);

	// Strip 4 (pin 5)
	fill_solid(leds, NUM_LEDS_FACE_FIVE, CRGB::Green);
	FastLED[4].showLeds(this_bright);

	// Strip 5 (pin 6)
	fill_solid(leds, NUM_LEDS_FACE_SIX, CRGB::Red);
	FastLED[5].showLeds(this_bright);
}

#endif
