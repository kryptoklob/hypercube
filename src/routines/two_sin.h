#ifndef TWO_SIN_H
#define TWO_SIN_H

/* Usage - two_sin();
 *
 * Loads of variables to play with
 *
 */

/* two_sin() - two sin waves going back and forth */

uint8_t that_hue = 140;      	// You can change the starting hue for other wave.
uint8_t that_rot = 6;        // You can change how quickly the hue rotates for the other wave. Currently 0.
int8_t that_speed = 3;       // You can change the speed, and use negative values.
int thatphase = 0;          	// Phase change value gets calculated.
uint8_t that_cutoff = 75;   	// You can change the cutoff value to alter wave length. Lower value = longer wave.

void two_sin() {

  if (this_dir == 0) {this_phase += this_speed; thatphase += that_speed;}
  else {this_phase -= this_speed; thatphase -= that_speed;}

  this_hue = this_hue + this_rot;   // Hue rotation is fun for this_wave.
  that_hue = that_hue + that_rot;   // It's also fun for thatwave.

  for (int k=0; k<NUM_LEDS_MIN-1; k++) {
    // qsub sets a minimum value called this_cutoff.
    // qsub < this_cutoff, then bright = 0, otherwise bright = 256
    int this_bright = qsuba(cubicwave8((k*all_freq)+this_phase), this_cutoff);

    // Assign hues & brightness
    // Right now it just sets all arrays to the same thing
    leds_face_one[k] = CHSV(this_hue, this_sat, this_bright);
    leds_face_two[k] = CHSV(this_hue, this_sat, this_bright);
    leds_face_three[k] = CHSV(this_hue, this_sat, this_bright);
    leds_face_four[k] = CHSV(this_hue, this_sat, this_bright);
    leds_face_five[k] = CHSV(this_hue, this_sat, this_bright);
    leds_face_six[k] = CHSV(this_hue, this_sat, this_bright);
  }
}

#endif
