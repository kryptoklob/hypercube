#ifndef CUBE_TEST_PARALLEL_H
#define CUBE_TEST_PARALLEL_H

/* Usage - cube_test_parallel(); */

void cube_test_parallel() {
	// Pulse the brightness

	this_bright=255;
	this_hue++;

	// Strip 1 (pin 2)
	leds(0, 57) = CHSV(this_hue, 255, 255);
  leds(58, 117) = CHSV(this_hue+20, 255, 255);
  leds(118, 178) = CHSV(this_hue+40, 255, 255);
  leds(178,238) = CHSV(this_hue+60, 255, 255);
	FastLED[0].showLeds(this_bright);

	// Strip 2 (pin 3)
	leds(0, 57) = CHSV(40 255, 255);
  leds(58, 117) = CHSV(50, 255, 255);
  leds(118, 178) = CHSV(60, 255, 255);
  leds(178,238) = CHSV(70, 255, 255);
	FastLED[1].showLeds(this_bright);

	// Strip 3 (pin 4)
	leds(0, 57) = CHSV(80, 255, 255);
  leds(58, 117) = CHSV(90, 255, 255);
  leds(118, 178) = CHSV(100, 255, 255);
  leds(178,232) = CHSV(110, 255, 255);
	FastLED[2].showLeds(this_bright);

	// Strip 4 (pin 5)
	leds(0, 57) = CHSV(120, 255, 255);
  leds(58, 117) = CHSV(130, 255, 255);
  leds(118, 178) = CHSV(140, 255, 255);
  leds(178,236) = CHSV(150, 255, 255);
	FastLED[3].showLeds(this_bright);

	// Strip 5 (pin 6)
	leds(0, 57) = CHSV(160, 255, 255);
  leds(58, 117) = CHSV(170, 255, 255);
  leds(118, 178) = CHSV(180, 255, 255);
  leds(178,237) = CHSV(190, 255, 255);
	FastLED[4].showLeds(this_bright);

	// Strip 6 (pin 7)
	leds(0, 57) = CHSV(200, 255, 255);
  leds(58, 117) = CHSV(210, 255, 255);
  leds(118, 178) = CHSV(220, 255, 255);
  leds(178,232) = CHSV(230, 255, 255);
	FastLED[5].showLeds(this_bright);
}

#endif
