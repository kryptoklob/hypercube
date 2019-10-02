// ---------- COMPILE VARS ---------- //

// Disables Version "errors" on compile
#define FASTLED_INTERNAL

// Libraries
#include <FastLED.h>
#include "EEPROM.h"

// Unsigned subtraction magic
#define qsubd(x, b) ((x>b)?wave_brightness:0)
#define qsuba(x, b) ((x>b)?x-b:0)

// Serial vars
#define SERIAL_BAUDRATE 57600
#define SERIAL_TIMEOUT 1500

// Arduino pin setup
#define LED_PIN_ONE 2
#define LED_PIN_TWO 3
#define LED_PIN_THREE 4
#define LED_PIN_FOUR 5
#define LED_PIN_FIVE 6
#define LED_PIN_SIX 7

// LED Meta Defines
#define COLOR_ORDER GRB // (ws2812b)
#define LED_TYPE WS2812B

// Six faces, each with exactly 144 leds

// Some useful extra defines here
#define NUM_LEDS_PER_STRIP 144
#define STARTMODE 2

// ---------- RUNTIME VARS ---------- //

// Serial Variables
byte in_byte;
int this_arg;

// LED Meta Variables

// The actual led data arrays (see RGBSet / CRGBArray reference on FastLED Github)
CRGBArray<NUM_LEDS_PER_STRIP> leds_face_one;
CRGBArray<NUM_LEDS_PER_STRIP> leds_face_two;
CRGBArray<NUM_LEDS_PER_STRIP> leds_face_three;
CRGBArray<NUM_LEDS_PER_STRIP> leds_face_four;
CRGBArray<NUM_LEDS_PER_sTRIP> leds_face_five;
CRGBArray<NUM_LEDS_PER_STRIP> leds_face_six;

// LED Overall Variables
uint8_t max_bright  = 255;
uint8_t max_mode    = 100;
uint8_t led_mode;

// LED Routine/Shared Variables
bool    glitter         = 0;      // Glitter flag
uint8_t this_bright     = 255;    // Standard brightness
uint8_t this_delay      = 0;      // Standard delay
uint8_t this_diff       = 1;      // Standard index jump
uint8_t this_dir        = 0;      // Standard direction
uint8_t this_fade       = 224;    // Standard fate rate
uint8_t this_hue        = 0;      // Standard hue
uint8_t this_index      = 0;      // Used to change starting position for effects
uint8_t this_rot        = 1;      // Standard hue rotation rate
uint8_t this_sat        = 255;    // Standard saturation
uint8_t this_speed      = 4;      // Standard speed change
uint8_t wave_brightness = 255;    // Brightness of the waves/bars

// Sine-wave routine vars
int this_phase = 0;               // Standard phase change
uint8_t all_freq = 2;            // Overall wave frequency
uint8_t this_cutoff = 192;        // Lower = longer waves, higher = shorter waves
uint8_t xd[NUM_LEDS_MIN];         // X-array for 2d coordinates of leds
uint8_t yd[NUM_LEDS_MIN];         // Y-array for 2d coordinates of leds
