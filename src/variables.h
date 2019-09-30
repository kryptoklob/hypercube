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

// Six faces, each with nominally 240 leds, actual numbers vary slightly
#define NUM_LEDS_FACE_ONE 238
#define NUM_LEDS_FACE_TWO 238
#define NUM_LEDS_FACE_THREE 232
#define NUM_LEDS_FACE_FOUR 236
#define NUM_LEDS_FACE_FIVE 237
#define NUM_LEDS_FACE_SIX 232

// It's helpful to know which set of leds are on which face AND side

// should add up to NUM_LEDS_FACE_ONE (238)
#define NUM_LEDS_FACE_ONE_SIDE_ONE 60
#define NUM_LEDS_FACE_ONE_SIDE_TWO 60
#define NUM_LEDS_FACE_ONE_SIDE_THREE 60
#define NUM_LEDS_FACE_ONE_SIDE_FOUR 60

// should add up to NUM_LEDS_FACE_TWO (238)
#define NUM_LEDS_FACE_TWO_SIDE_ONE
#define NUM_LEDS_FACE_TWO_SIDE_TWO
#define NUM_LEDS_FACE_TWO_SIDE_THREE
#define NUM_LEDS_FACE_TWO_SIDE_FOUR

// should add up to NUM_LEDS_FACE_THREE (232)
#define NUM_LEDS_FACE_THREE_SIDE_ONE
#define NUM_LEDS_FACE_THREE_SIDE_TWO
#define NUM_LEDS_FACE_THREE_SIDE_THREE
#define NUM_LEDS_FACE_THREE_SIDE_FOUR

// should add up to NUM_LEDS_FACE_FOUR (236)
#define NUM_LEDS_FACE_FOUR_SIDE_ONE
#define NUM_LEDS_FACE_FOUR_SIDE_TWO
#define NUM_LEDS_FACE_FOUR_SIDE_THREE
#define NUM_LEDS_FACE_FOUR_SIDE_FOUR

// should add up to NUM_LEDS_FACE_FIVE (237)
#define NUM_LEDS_FACE_FIVE_SIDE_ONE
#define NUM_LEDS_FACE_FIVE_SIDE_TWO
#define NUM_LEDS_FACE_FIVE_SIDE_THREE
#define NUM_LEDS_FACE_FIVE_SIDE_FOUR

// should add up to NUM_LEDS_FACE_SIX (232)
#define NUM_LEDS_FACE_SIX_SIDE_ONE
#define NUM_LEDS_FACE_SIX_SIDE_TWO
#define NUM_LEDS_FACE_SIX_SIDE_THREE
#define NUM_LEDS_FACE_SIX_SIDE_FOUR

// Some useful extra defines here
#define NUM_LEDS_PER_STRIP 240
#define NUM_LEDS_MAX 240
#define STARTMODE 2
#define STRANDLEN 240

// ---------- RUNTIME VARS ---------- //

// Serial Variables
byte in_byte;
int this_arg;

// LED Meta Variables
struct CRGB realleds[NUM_LEDS_MAX];     // The real LED array
CRGBSet leds(realleds, NUM_LEDS_MAX);   // See RGBSet Reference on FastLED Github

// LED Overall Variables
uint8_t max_bright  = 255;
uint8_t max_mode    = 100;
uint8_t demo_run    = 0;
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
uint8_t all_freq = 32;            // Overall wave frequency
uint8_t this_cutoff = 192;        // Lower = longer waves, higher = shorter waves
uint8_t xd[NUM_LEDS_PER_STRIP];   // X-array for 2d coordinates of leds
uint8_t yd[NUM_LEDS_PER_STRIP];   // Y-array for 2d coordinates of leds
