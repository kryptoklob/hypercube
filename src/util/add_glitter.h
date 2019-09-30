#ifndef ADDGLITTER_H
#define ADDGLITTER_H

/* Adds glitter to all strips, randomly
 *
 * The higher the input the more glitter we'll get every frame
 * */

void addglitter( fract8 chanceOfGlitter)
{
  if( random8() < chanceOfGlitter) {
    leds_face_one[random8()*(NUM_LEDS_FACE_ONE-1)] += CRGB::White;
    leds_face_two[random8()*(NUM_LEDS_FACE_TWO-1)] += CRGB::White;
    leds_face_three[random8()*(NUM_LEDS_FACE_THREE-1)] += CRGB::White;
    leds_face_four[random8()*(NUM_LEDS_FACE_FOUR-1)] += CRGB::White;
    leds_face_five[random8()*(NUM_LEDS_FACE_FIVE-1)] += CRGB::White;
    leds_face_six[random8()*(NUM_LEDS_FACE_SIX-1)] += CRGB::White;
  }
}

#endif
