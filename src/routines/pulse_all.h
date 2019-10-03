#ifndef PULSE_ALL_H
#define PULSE_ALL_H

/* Usage - pulse_all(); */

void pulse_all() {
	// Stays between 100 and 240 brightness ideally
	if (this_bright <= 100) { this_hue= random8(); this_dir = 1;}
	else if (this_bright >= 240) {this_dir = 0;}

	if (this_dir == 0 ) { this_bright-=9; }
	else if (this_dir == 1 ) { this_bright+=1; }

	leds_one(0, NUM_LEDS_PER_STRIP) = CHSV(this_hue, 255, this_bright);
	leds_two(0, NUM_LEDS_PER_STRIP) = CHSV(this_hue, 255, this_bright);
	leds_three(0, NUM_LEDS_PER_STRIP) = CHSV(this_hue, 255, this_bright);
	leds_four(0, NUM_LEDS_PER_STRIP) = CHSV(this_hue, 255, this_bright);
	leds_five(0, NUM_LEDS_PER_STRIP) = CHSV(this_hue, 255, this_bright);
}

#endif
