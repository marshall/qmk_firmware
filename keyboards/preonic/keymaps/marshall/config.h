#pragma once

#ifdef AUDIO_ENABLE
    #define LOWER_SOUND S__NOTE(_EF5), W__NOTE(_REST), Q__NOTE(_E4)
    #define RAISE_SOUND S__NOTE(_E4), W__NOTE(_REST), Q__NOTE(_EF5)
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(LOWER_SOUND), \
                                  SONG(RAISE_SOUND), \
                                  SONG(PREONIC_SOUND), \
                                  SONG(TERMINAL_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#ifndef TAPPING_TERM
#define TAPPING_TERM 175
#endif
