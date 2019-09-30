#ifndef CLEAR_ALL_H
#define CLEAR_ALL_H

/* Usage - clear_all(); */

void clear_all() {
	// Blank out every strip

  fill_solid(leds_face_one, NUM_LEDS_FACE_ONE, CRGB(0,0,0));
  fill_solid(leds_face_two, NUM_LEDS_FACE_TWO, CRGB(0,0,0));
  fill_solid(leds_face_three, NUM_LEDS_FACE_THREE, CRGB(0,0,0));
  fill_solid(leds_face_four, NUM_LEDS_FACE_FOUR, CRGB(0,0,0));
  fill_solid(leds_face_five, NUM_LEDS_FACE_FIVE, CRGB(0,0,0));
  fill_solid(leds_face_six, NUM_LEDS_FACE_SIX, CRGB(0,0,0));
}

#endif
