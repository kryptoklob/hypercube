#ifndef CUBE_TEST_PARALLEL_H
#define CUBE_TEST_PARALLEL_H

/* Usage - cube_test_parallel();
 *
 * This should clearly identify each "fourth" of a face
 * Should help determine where the endpoints are
 *
 * */

void cube_test_parallel() {
  // Every strip gets it's own color
  // The endpoints of each side should pulse a different color than the background

  // Set all faces to different colors
  leds_face_one.fill_solid(CRGB::Red);
  leds_face_two.fill_solid(CRGB::Green);
  leds_face_three.fill_solid(CRGB::Blue);
  leds_face_four.fill_solid(CRGB::Yellow);
  leds_face_five.fill_solid(CRGB::Aqua);
  leds_face_six.fill_solid(CRGB::Aquamarine);

  // Set the endpoints of each face's sides

  // face one
  leds_face_one[FACE_ONE_SIDE_ONE_START] = CRGB::Green;
  leds_face_one[FACE_ONE_SIDE_ONE_END] = CRGB::Green;

  leds_face_one[FACE_ONE_SIDE_TWO_START] = CRGB::Blue;
  leds_face_one[FACE_ONE_SIDE_TWO_END] = CRGB::Blue;

  leds_face_one[FACE_ONE_SIDE_THREE_START] = CRGB::Green;
  leds_face_one[FACE_ONE_SIDE_THREE_END] = CRGB::Green;

  leds_face_one[FACE_ONE_SIDE_FOUR_START] = CRGB::Blue;
  leds_face_one[FACE_ONE_SIDE_FOUR_END] = CRGB::Blue;

  // face two
  leds_face_two[FACE_TWO_SIDE_ONE_START] = CRGB::Red;
  leds_face_two[FACE_TWO_SIDE_ONE_END] = CRGB::Red;

  leds_face_two[FACE_TWO_SIDE_TWO_START] = CRGB::Blue;
  leds_face_two[FACE_TWO_SIDE_TWO_END] = CRGB::Blue;

  leds_face_two[FACE_TWO_SIDE_THREE_START] = CRGB::Red;
  leds_face_two[FACE_TWO_SIDE_THREE_END] = CRGB::Red;

  leds_face_two[FACE_TWO_SIDE_FOUR_START] = CRGB::Blue;
  leds_face_two[FACE_TWO_SIDE_FOUR_END] = CRGB::Blue;

  // face three
  leds_face_three[FACE_THREE_SIDE_ONE_START] = CRGB::Green;
  leds_face_three[FACE_THREE_SIDE_ONE_END] = CRGB::Green;

  leds_face_three[FACE_THREE_SIDE_TWO_START] = CRGB::Red;
  leds_face_three[FACE_THREE_SIDE_TWO_END] = CRGB::Red;

  leds_face_three[FACE_THREE_SIDE_THREE_START] = CRGB::Green;
  leds_face_three[FACE_THREE_SIDE_THREE_END] = CRGB::Green;

  leds_face_three[FACE_THREE_SIDE_FOUR_START] = CRGB::Red;
  leds_face_three[FACE_THREE_SIDE_FOUR_END] = CRGB::Red;

  // face four
  leds_face_four[FACE_FOUR_SIDE_ONE_START] = CRGB::Green;
  leds_face_four[FACE_FOUR_SIDE_ONE_END] = CRGB::Green;

  leds_face_four[FACE_FOUR_SIDE_TWO_START] = CRGB::Red;
  leds_face_four[FACE_FOUR_SIDE_TWO_END] = CRGB::Red;

  leds_face_four[FACE_FOUR_SIDE_THREE_START] = CRGB::Green;
  leds_face_four[FACE_FOUR_SIDE_THREE_END] = CRGB::Green;

  leds_face_four[FACE_FOUR_SIDE_FOUR_START] = CRGB::Red;
  leds_face_four[FACE_FOUR_SIDE_FOUR_END] = CRGB::Red;

  // face five
  leds_face_five[FACE_FIVE_SIDE_ONE_START] = CRGB::Green;
  leds_face_five[FACE_FIVE_SIDE_ONE_END] = CRGB::Green;

  leds_face_five[FACE_FIVE_SIDE_TWO_START] = CRGB::Blue;
  leds_face_five[FACE_FIVE_SIDE_TWO_END] = CRGB::Blue;

  leds_face_five[FACE_FIVE_SIDE_THREE_START] = CRGB::Green;
  leds_face_five[FACE_FIVE_SIDE_THREE_END] = CRGB::Green;

  leds_face_five[FACE_FIVE_SIDE_FOUR_START] = CRGB::Blue;
  leds_face_five[FACE_FIVE_SIDE_FOUR_END] = CRGB::Blue;

  // face six
  leds_face_six[FACE_SIX_SIDE_ONE_START] = CRGB::Green;
  leds_face_six[FACE_SIX_SIDE_ONE_END] = CRGB::Green;

  leds_face_six[FACE_SIX_SIDE_TWO_START] = CRGB::Red;
  leds_face_six[FACE_SIX_SIDE_TWO_END] = CRGB::Red;

  leds_face_six[FACE_SIX_SIDE_THREE_START] = CRGB::Green;
  leds_face_six[FACE_SIX_SIDE_THREE_END] = CRGB::Green;

  leds_face_six[FACE_SIX_SIDE_FOUR_START] = CRGB::Red;
  leds_face_six[FACE_SIX_SIDE_FOUR_END] = CRGB::Red;
}

#endif
