#ifndef CYLON_H
#define CYLON_H

/* Usage - CYLON(); */

void cylon() {
	// single dot moving back and forth across each strip
	// hue rotates
	// uses fadeToBlackBy to fade the colors out

	// direction and phase
	if (this_dir == 0) { this_phase++; }
	else { this_phase--; }

	if (this_phase >= NUM_LEDS_MIN/4 - 2) { this_dir = !this_dir; }
	if (this_phase == 0) { this_dir = !this_dir; }

	// bounce back and forth between the start and the end
	leds_face_one[this_phase] = CHSV(this_hue, 255, 255);
	leds_face_one[FACE_ONE_SIDE_TWO_END - this_phase] = CHSV(this_hue, 255, 255);
	leds_face_one[this_phase+FACE_ONE_SIDE_THREE_START] = CHSV(this_hue, 255, 255);
	leds_face_one[FACE_ONE_SIDE_FOUR_END - this_phase] = CHSV(this_hue, 255, 255);

	leds_face_two[FACE_TWO_SIDE_ONE_END-this_phase] = CHSV(this_hue, 255, 255);
	leds_face_two[FACE_TWO_SIDE_TWO_START + this_phase] = CHSV(this_hue, 255, 255);
	leds_face_two[FACE_TWO_SIDE_THREE_END-this_phase] = CHSV(this_hue, 255, 255);
	leds_face_two[FACE_TWO_SIDE_FOUR_START + this_phase] = CHSV(this_hue, 255, 255);

	leds_face_three[this_phase] = CHSV(this_hue, 255, 255);
	leds_face_three[FACE_THREE_SIDE_TWO_END - this_phase] = CHSV(this_hue, 255, 255);
	leds_face_three[this_phase+FACE_THREE_SIDE_THREE_START] = CHSV(this_hue, 255, 255);
	leds_face_three[FACE_THREE_SIDE_FOUR_END - this_phase] = CHSV(this_hue, 255, 255);

	leds_face_four[FACE_FOUR_SIDE_ONE_END-this_phase] = CHSV(this_hue, 255, 255);
	leds_face_four[FACE_FOUR_SIDE_TWO_START + this_phase] = CHSV(this_hue, 255, 255);
	leds_face_four[FACE_FOUR_SIDE_THREE_END-this_phase] = CHSV(this_hue, 255, 255);
	leds_face_four[FACE_FOUR_SIDE_FOUR_START + this_phase] = CHSV(this_hue, 255, 255);

	leds_face_five[this_phase] = CHSV(this_hue, 255, 255);
	leds_face_five[FACE_FIVE_SIDE_TWO_END - this_phase] = CHSV(this_hue, 255, 255);
	leds_face_five[this_phase+FACE_FIVE_SIDE_THREE_START] = CHSV(this_hue, 255, 255);
	leds_face_five[FACE_FIVE_SIDE_FOUR_END - this_phase] = CHSV(this_hue, 255, 255);

	leds_face_six[FACE_SIX_SIDE_ONE_END-this_phase] = CHSV(this_hue, 255, 255);
	leds_face_six[FACE_SIX_SIDE_TWO_START + this_phase] = CHSV(this_hue, 255, 255);
	leds_face_six[FACE_SIX_SIDE_THREE_END-this_phase] = CHSV(this_hue, 255, 255);
	leds_face_six[FACE_SIX_SIDE_FOUR_START + this_phase] = CHSV(this_hue, 255, 255);

  leds_face_one.fadeToBlackBy(that_fade);
  leds_face_two.fadeToBlackBy(that_fade);
  leds_face_three.fadeToBlackBy(that_fade);
  leds_face_four.fadeToBlackBy(that_fade);
  leds_face_five.fadeToBlackBy(that_fade);
  leds_face_six.fadeToBlackBy(that_fade);

	this_hue++;
}

#endif
