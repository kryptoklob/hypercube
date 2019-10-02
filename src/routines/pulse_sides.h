#ifndef PULSE_SIDES_H
#define PULSE_SIDES_H

/* Usage - pulse_sides(); */

void pulse_sides() {
	// Pulse the brightness sides quickly (at random)
	// Red, green, blue only so that we can use max brightness

	// Randomly pick a side if we're done with another side
	if (this_bright <= 100) {
		this_index = random8() % 6;
		this_hue = random8();
		this_dir = 0;
	} else if (this_bright >= 240) {
		this_dir = 1;
	}

	// Pulse it bright and then back
	// We should be using an array of all of our arrays yet, but pointer bullshit
	// is too much to figure out right now, so here's a dumb switch statement:
	switch (this_index) {
		case 0:
			leds_face_one(0, NUM_LEDS_FACE_ONE-1) = CHSV(this_hue, 255, this_bright);
			break;
		case 1:
			leds_face_two(0, NUM_LEDS_FACE_TWO-1) = CHSV(this_hue, 255, this_bright);
			break;
		case 2:
			leds_face_three(0, NUM_LEDS_FACE_THREE-1) = CHSV(this_hue, 255, this_bright);
			break;
		case 3:
			leds_face_four(0, NUM_LEDS_FACE_FOUR-1) = CHSV(this_hue, 255, this_bright);
			break;
		case 4:
			leds_face_five(0, NUM_LEDS_FACE_FIVE-1) = CHSV(this_hue, 255, this_bright);
			break;
		case 5:
			leds_face_six(0, NUM_LEDS_FACE_SIX-1) = CHSV(this_hue, 255, this_bright);
			break;
	}

	if (this_dir == 0) { this_bright+=9; }
	else { this_bright-=9; }
}

#endif
