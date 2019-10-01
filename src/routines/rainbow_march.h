#ifndef RAINBOW_MARCH_H
#define RAINBOW_MARCH_H

/* Very simple rainbow-fill with rotating colors */

void rainbow_march() {
	/*
  leds_face_one.fill_rainbow(this_hue);
  leds_face_two.fill_rainbow(this_hue);
  leds_face_three.fill_rainbow(this_hue);
  leds_face_four.fill_rainbow(this_hue);
  leds_face_five.fill_rainbow(this_hue);
  leds_face_six.fill_rainbow(this_hue);
	*/

	leds_face_one(FACE_ONE_SIDE_ONE_START, FACE_ONE_SIDE_ONE_END).fill_rainbow(this_hue+45, -5);
	leds_face_one(FACE_ONE_SIDE_TWO_START, FACE_ONE_SIDE_TWO_END).fill_rainbow(this_hue+45, -5);
	leds_face_one(FACE_ONE_SIDE_THREE_START, FACE_ONE_SIDE_THREE_END).fill_rainbow(this_hue, 5);
	leds_face_one(FACE_ONE_SIDE_FOUR_START, FACE_ONE_SIDE_FOUR_END).fill_rainbow(this_hue, 5);

	leds_face_two(FACE_TWO_SIDE_ONE_START, FACE_TWO_SIDE_ONE_END).fill_rainbow(this_hue, 5);
	leds_face_two(FACE_TWO_SIDE_TWO_START, FACE_TWO_SIDE_TWO_END).fill_rainbow(this_hue, 5);
	leds_face_two(FACE_TWO_SIDE_THREE_START, FACE_TWO_SIDE_THREE_END).fill_rainbow(this_hue+45, -5);
	leds_face_two(FACE_TWO_SIDE_FOUR_START, FACE_TWO_SIDE_FOUR_END).fill_rainbow(this_hue+45, -5);

	leds_face_three(FACE_THREE_SIDE_ONE_START, FACE_THREE_SIDE_ONE_END).fill_rainbow(this_hue+45, -5);
	leds_face_three(FACE_THREE_SIDE_TWO_START, FACE_THREE_SIDE_TWO_END).fill_rainbow(this_hue+45, -5);
	leds_face_three(FACE_THREE_SIDE_THREE_START, FACE_THREE_SIDE_THREE_END).fill_rainbow(this_hue, 5);
	leds_face_three(FACE_THREE_SIDE_FOUR_START, FACE_THREE_SIDE_FOUR_END).fill_rainbow(this_hue, 5);

	leds_face_four(FACE_FOUR_SIDE_ONE_START, FACE_FOUR_SIDE_ONE_END).fill_rainbow(this_hue, 5);
	leds_face_four(FACE_FOUR_SIDE_TWO_START, FACE_FOUR_SIDE_TWO_END).fill_rainbow(this_hue, 5);
	leds_face_four(FACE_FOUR_SIDE_THREE_START, FACE_FOUR_SIDE_THREE_END).fill_rainbow(this_hue+45, -5);
	leds_face_four(FACE_FOUR_SIDE_FOUR_START, FACE_FOUR_SIDE_FOUR_END).fill_rainbow(this_hue+45, -5);

	leds_face_five(FACE_FIVE_SIDE_ONE_START, FACE_FIVE_SIDE_ONE_END).fill_rainbow(this_hue+45, -5);
	leds_face_five(FACE_FIVE_SIDE_TWO_START, FACE_FIVE_SIDE_TWO_END).fill_rainbow(this_hue+45, -5);
	leds_face_five(FACE_FIVE_SIDE_THREE_START, FACE_FIVE_SIDE_THREE_END).fill_rainbow(this_hue, 5);
	leds_face_five(FACE_FIVE_SIDE_FOUR_START, FACE_FIVE_SIDE_FOUR_END).fill_rainbow(this_hue, 5);

	leds_face_six(FACE_SIX_SIDE_ONE_START, FACE_SIX_SIDE_ONE_END).fill_rainbow(this_hue, 5);
	leds_face_six(FACE_SIX_SIDE_TWO_START, FACE_SIX_SIDE_TWO_END).fill_rainbow(this_hue, 5);
	leds_face_six(FACE_SIX_SIDE_THREE_START, FACE_SIX_SIDE_THREE_END).fill_rainbow(this_hue+45, -5);
	leds_face_six(FACE_SIX_SIDE_FOUR_START, FACE_SIX_SIDE_FOUR_END).fill_rainbow(this_hue+45, -5);

  this_hue+= 2;
}

#endif
