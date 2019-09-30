#ifndef RAINBOW_MARCH_H
#define RAINBOW_MARCH_H

/* Very simple rainbow-fill with rotating colors */

void rainbow_march() {
  leds_face_one.fill_rainbow(this_hue);
  leds_face_two.fill_rainbow(this_hue);
  leds_face_three.fill_rainbow(this_hue);
  leds_face_four.fill_rainbow(this_hue);
  leds_face_five.fill_rainbow(this_hue);
  leds_face_six.fill_rainbow(this_hue);

  this_hue++;
}

#endif
