#ifndef ALL_HUE_ROTATE_H
#define ALL_HUE_ROTATE_H

void all_hue_rotate() {
  leds_one.fill_solid(this_hue);
  leds_two.fill_solid(this_hue);
  leds_three.fill_solid(this_hue);
  leds_four.fill_solid(this_hue);
  leds_five.fill_solid(this_hue);

  this_hue+= 2;
}

#endif
