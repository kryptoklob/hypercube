#ifndef SELF_DESTRUCT_H
#define SELF_DESTRUCT_H

/* Usage - self_destruct(); */
bool in_delay_section = 0;
uint16_t that_delay = 2000;
uint8_t that_fade = 64;

void self_destruct() {
	// Red, green, blue only so that we can use max brightness
	// Grouping of red dots (a wave) that quickly moves up the cube
	// The frequency that the dots appear increases with time,
	// until the entire cube is encased in red.

	//if (that_delay == 0) { that_delay = 2000; }

	// We can use fadeToBlackBy here to make the dots leave a trail

	// face one
	leds_face_one(constrain(this_phase, 0, FACE_ONE_SIDE_TWO_END), constrain(this_phase+16, 0, FACE_ONE_SIDE_TWO_END)) = CHSV(that_hue, 255, 255);
	leds_face_one(constrain(NUM_LEDS_FACE_ONE-this_phase-16, FACE_ONE_SIDE_THREE_START, FACE_ONE_SIDE_FOUR_END), constrain(NUM_LEDS_FACE_ONE-this_phase, FACE_ONE_SIDE_THREE_START, FACE_ONE_SIDE_FOUR_END)) = CHSV(that_hue, 255, 255);

	// face two
	leds_face_two(constrain(FACE_TWO_SIDE_TWO_END-this_phase, 0, FACE_TWO_SIDE_TWO_END), constrain(FACE_TWO_SIDE_TWO_END-this_phase-16, 0, FACE_TWO_SIDE_TWO_END)) = CHSV(that_hue, 255, 255);
	leds_face_two(constrain(this_phase+FACE_TWO_SIDE_THREE_START, FACE_TWO_SIDE_THREE_START, FACE_TWO_SIDE_FOUR_END), constrain(this_phase+16, FACE_TWO_SIDE_THREE_START, FACE_TWO_SIDE_FOUR_END)) = CHSV(that_hue, 255, 255);

	// face three
	leds_face_three(constrain(this_phase, 0, FACE_THREE_SIDE_TWO_END), constrain(this_phase+16, 0, FACE_THREE_SIDE_TWO_END)) = CHSV(that_hue, 255, 255);
	leds_face_three(constrain(NUM_LEDS_FACE_THREE-this_phase-16, FACE_THREE_SIDE_THREE_START, FACE_THREE_SIDE_FOUR_END), constrain(NUM_LEDS_FACE_THREE-this_phase, FACE_THREE_SIDE_THREE_START, FACE_THREE_SIDE_FOUR_END)) = CHSV(that_hue, 255, 255);

	// face four
	leds_face_four(constrain(FACE_FOUR_SIDE_TWO_END-this_phase, 0, FACE_FOUR_SIDE_TWO_END), constrain(FACE_FOUR_SIDE_TWO_END-this_phase-16, 0, FACE_FOUR_SIDE_TWO_END)) = CHSV(that_hue, 255, 255);
	leds_face_four(constrain(this_phase+FACE_FOUR_SIDE_THREE_START, FACE_FOUR_SIDE_THREE_START, FACE_FOUR_SIDE_FOUR_END), constrain(this_phase+16, FACE_FOUR_SIDE_THREE_START, FACE_FOUR_SIDE_FOUR_END)) = CHSV(that_hue, 255, 255);

	// face five
	leds_face_five(constrain(this_phase, 0, FACE_FIVE_SIDE_TWO_END), constrain(this_phase+16, 0, FACE_FIVE_SIDE_TWO_END)) = CHSV(that_hue, 255, 255);
	leds_face_five(constrain(NUM_LEDS_FACE_FIVE-this_phase-16, FACE_FIVE_SIDE_THREE_START, FACE_FIVE_SIDE_FOUR_END), constrain(NUM_LEDS_FACE_FIVE-this_phase, FACE_FIVE_SIDE_THREE_START, FACE_FIVE_SIDE_FOUR_END)) = CHSV(that_hue, 255, 255);

	// face six
	leds_face_six(constrain(FACE_SIX_SIDE_TWO_END-this_phase, 0, FACE_SIX_SIDE_TWO_END), constrain(FACE_SIX_SIDE_TWO_END-this_phase-16, 0, FACE_SIX_SIDE_TWO_END)) = CHSV(that_hue, 255, 255);
	leds_face_six(constrain(this_phase+FACE_SIX_SIDE_THREE_START, FACE_SIX_SIDE_THREE_START, FACE_SIX_SIDE_FOUR_END), constrain(this_phase+16, FACE_SIX_SIDE_THREE_START, FACE_SIX_SIDE_FOUR_END)) = CHSV(that_hue, 255, 255);

	leds_face_one.fadeToBlackBy(that_fade);
	leds_face_two.fadeToBlackBy(that_fade);
	leds_face_three.fadeToBlackBy(that_fade);
	leds_face_four.fadeToBlackBy(that_fade);
	leds_face_five.fadeToBlackBy(that_fade);
	leds_face_six.fadeToBlackBy(that_fade);
	this_phase+=12;

	if (this_phase >= NUM_LEDS_MIN/2 + 140) { /*clear_all(); FastLED.show();*/ if(that_delay != 0){FastLED.delay(that_delay);} this_phase = 0; if(that_delay != 0) {that_delay -= 100;} that_fade--; if (that_fade == 0) {that_fade = 64;} }

	that_hue++;

	/*
	// Pulse it bright and then back
	// We should be using an array of all of our arrays yet, but pointer bullshit
	// is too much to figure out right now, so here's a dumb switch statement:
	switch (this_index) {
		case 0:
			leds_face_one(0, NUM_LEDS_FACE_TWO) = CHSV(this_hue, 255, this_bright);
			break;
		case 1:
			leds_face_two(0, NUM_LEDS_FACE_TWO) = CHSV(this_hue, 255, this_bright);
			break;
		case 2:
			leds_face_three(0, NUM_LEDS_FACE_THREE) = CHSV(this_hue, 255, this_bright);
			break;
		case 3:
			leds_face_four(0, NUM_LEDS_FACE_FOUR) = CHSV(this_hue, 255, this_bright);
			break;
		case 4:
			leds_face_five(0, NUM_LEDS_FACE_FIVE) = CHSV(this_hue, 255, this_bright);
			break;
		case 5:
			leds_face_six(0, NUM_LEDS_FACE_SIX) = CHSV(this_hue, 255, this_bright);
			break;
	}

	if (this_dir == 0) { this_bright+=9; }
	else { this_bright-=9; }
	*/
}

#endif
