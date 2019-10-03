#ifndef ADDGLITTER_H
#define ADDGLITTER_H

/* Adds glitter to all strips, randomly
 *
 * The higher the input the more glitter we'll get every frame
 * */

void addglitter( fract8 chanceOfGlitter)
{
  if( random8() < chanceOfGlitter) {
    leds_one[random8()*(NUM_LEDS_PER_STRIP-1)] += CRGB::White;
    leds_two[random8()*(NUM_LEDS_PER_STRIP-1)] += CRGB::White;
    leds_three[random8()*(NUM_LEDS_PER_STRIP-1)] += CRGB::White;
    leds_four[random8()*(NUM_LEDS_PER_STRIP-1)] += CRGB::White;
    leds_five[random8()*(NUM_LEDS_PER_STRIP-1)] += CRGB::White;
  }
}

#endif
