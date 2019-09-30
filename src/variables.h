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

// Single pin (2) defined for development testing
#define LED_PIN_ONE 2
#define LED_PIN_TWO 3
#define LED_PIN_THREE 4
#define LED_PIN_FOUR 5
#define LED_PIN_FIVE 6
#define LED_PIN_SIX 7

// LED Meta Defines
#define COLOR_ORDER GRB

#define LED_TYPE WS2812B

// Six faces, each with nominally 240 leds, actual numbers vary slightly
#define NUM_LEDS_FACE_ONE 238 // red
#define NUM_LEDS_FACE_TWO 238 // blue
#define NUM_LEDS_FACE_THREE 232 // green
#define NUM_LEDS_FACE_FOUR 236 // purple
#define NUM_LEDS_FACE_FIVE 237 // yellow
#define NUM_LEDS_FACE_SIX 232 // white
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
CRGBPalette16 current_palette;         // Current palette we're using
CRGBPalette16 target_palette;          // Next palette to transition to
TBlendType current_blending;           // Linear vs No-Blending
extern const TProgmemRGBGradientPalettePtr g_gradient_palettes[];   // from gradient_palettes.h
extern const uint8_t g_gradient_palette_count;                      // # of fixed palettes
uint8_t g_current_palette_number  = 0;                              // Current palette number
uint8_t current_pattern_index     = 0;                              // Index of current pattern
uint8_t default_mode              = 34;                             // Default mode to go to

// LED Overall Variables
uint8_t max_bright  = 255;
uint8_t max_mode    = 100;
uint8_t demo_run    = 0;
uint8_t led_mode;

// LED Routine/Shared Variables
uint8_t all_freq        = 32;     // Frequency (width of bars) (sine-routines)
uint8_t bg_clr          = 0;      // Background color
uint8_t bg_bri          = 20;      // Background brightness
bool    glitter         = 0;      // Glitter flag
uint8_t palette_change;           // 1 = similiar pallete, 2 = random4 palette, 3 = random16 palette
uint8_t start_index     = 0;      // Foreground hue to start with (sine-routines)
uint8_t this_beat;                // Beat tracker (juggle routine)
uint8_t this_bright     = 255;      // Starndard brightness
uint8_t this_cutoff     = 192;    // Cuttoff value; lower = longer wave
int     this_delay      = 0;      // Standard delay
uint8_t this_diff       = 1;      // Standard palette index jump
uint8_t this_dir        = 0;      // Standard direction
uint8_t this_fade       = 224;    // Standard fate rate
uint8_t this_hue        = 0;      // Standard hue
uint8_t this_index      = 0;      // Standard pallete index
uint8_t this_inc        = 1;      // Changes starting color for each pass (sine-routines)
int     this_phase      = 0;      // Standard phase change
uint8_t this_rot        = 1;      // Standard hue rotation rate
uint8_t this_sat        = 255;    // Standard saturdation
uint8_t this_speed      = 4;      // Standard speed change
uint8_t wave_brightness = 255;    // Brightness of the waves/bars
uint8_t xd[NUM_LEDS_PER_STRIP];             // X-array for 2d coordinates of leds
uint8_t yd[NUM_LEDS_PER_STRIP];             // Y-array for 2d coordinates of leds
