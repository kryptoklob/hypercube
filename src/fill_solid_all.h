#ifndef FILL_SOLID_ALL_H
#define FILL_SOLID_ALL_H

/* Usage - fill_solid_all(); */

void fill_solid_all() {
	// Set every strip to this_hue, this_sat, this_bright
  fill_solid(leds_face_one, NUM_LEDS_FACE_ONE, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_face_two, NUM_LEDS_FACE_TWO, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_face_three, NUM_LEDS_FACE_THREE, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_face_four, NUM_LEDS_FACE_FOUR, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_face_five, NUM_LEDS_FACE_FIVE, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_face_six, NUM_LEDS_FACE_SIX, CHSV(this_hue,this_sat,this_bright));
}

#endif
