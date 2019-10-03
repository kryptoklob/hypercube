#ifndef CYLON_H
#define CYLON_H

/* Usage - CYLON(); */

void cylon() {

	// this_index = position of the lit led
	// this_dir = direction it's moving (zero is towards end of strip, 1 is reverse
	// this_delay, as usual is used to adjust the speed of the animation
	// this_hue = 0 (red)

	// increment or decrement the index as needed
	if (this_dir == 0) this_index++;
	else if (this_dir == 1) this_index--;

	if (this_index == 0 ) this_dir = 1;
	else if (this_index == NUM_LEDS_PER_STRIP-1) this_dir = 0;

	leds_one[this_index] = CHSV(this_hue, 255, 255);
	leds_two[this_index] = CHSV(this_hue, 255, 255);
	leds_three[this_index] = CHSV(this_hue, 255, 255);
	leds_four[this_index] = CHSV(this_hue, 255, 255);
	leds_five[this_index] = CHSV(this_hue, 255, 255);

	// Because rainbows are fun
	this_hue++;
}

#endif
