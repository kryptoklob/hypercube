#ifndef FILL_SOLID_ALL_H
#define FILL_SOLID_ALL_H

/* Usage - fill_solid_all(); */

void fill_solid_all() {
	// Set every strip to this_hue, this_sat, this_bright
  fill_solid(leds_one, NUM_LEDS_PER_STRIP, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_two, NUM_LEDS_PER_STRIP, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_three, NUM_LEDS_PER_STRIP, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_four, NUM_LEDS_PER_STRIP, CHSV(this_hue,this_sat,this_bright));
  fill_solid(leds_five, NUM_LEDS_PER_STRIP, CHSV(this_hue,this_sat,this_bright));
}

#endif
