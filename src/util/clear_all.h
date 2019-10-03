#ifndef CLEAR_ALL_H
#define CLEAR_ALL_H

/* Usage - clear_all(); */

void clear_all() {
	// Blank out every strip

  fill_solid(leds_one, NUM_LEDS_PER_STRIP, CRGB(0,0,0));
  fill_solid(leds_two, NUM_LEDS_PER_STRIP, CRGB(0,0,0));
  fill_solid(leds_three, NUM_LEDS_PER_STRIP, CRGB(0,0,0));
  fill_solid(leds_four, NUM_LEDS_PER_STRIP, CRGB(0,0,0));
  fill_solid(leds_five, NUM_LEDS_PER_STRIP, CRGB(0,0,0));
}

#endif
