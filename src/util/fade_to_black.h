#ifndef FADE_TO_BLACK_H
#define FADE_TO_BLACK_H

/* Usage - fade_to_black(); */

void fade_to_black() {
	for(uint8_t i = 255; i>0; i-=25) {
		FastLED.setBrightness(i);
		FastLED.show();
	}
}

#endif
