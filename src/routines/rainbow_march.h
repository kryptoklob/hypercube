#ifndef RAINBOW_MARCH_H
#define RAINBOW_MARCH_H

/* Very simple rainbow-fill with rotating colors */

void rainbow_march() {
  leds_one.fill_rainbow(this_hue);
  leds_two.fill_rainbow(this_hue);
  leds_three.fill_rainbow(this_hue);
  leds_four.fill_rainbow(this_hue);
  leds_five.fill_rainbow(this_hue);

  this_hue+= 2;
}

#endif
