#ifndef CONFIG_SAFEGUARDS_H
#define CONFIG_SAFEGUARDS_H

/*****************************
 * COMPATIBILITY SAFE GUARDS *
 *****************************/

/**
 * NOTE: Only mess with these if you know what you're doing!
 * These are put in place to insure that connected functionality works as intended.
 */

/*****************
 * config_debug.h
 */
#if RELEASE_ROM
    #undef DETERMINISTIC_BUILD
    #undef SKIP_N64_BOOT_LOGO
    #undef BOOT_TO_SCENE
    #undef BOOT_TO_SCENE_NEW_GAME_ONLY
    #undef BOOT_TO_FILE_SELECT
    #undef DISABLE_DEBUG_FEATURES

    #define DETERMINISTIC_BUILD false
    #define SKIP_N64_BOOT_LOGO false
    #define BOOT_TO_SCENE false
    #define BOOT_TO_SCENE_NEW_GAME_ONLY false
    #define BOOT_TO_FILE_SELECT false
    #define DISABLE_DEBUG_FEATURES true
#endif

#if DISABLE_DEBUG_FEATURES
    #undef SHOW_CS_INFOS
    #undef SHOW_INPUT_DISPLAY
    #undef SHOW_TIME_INFOS
    #undef INCLUDE_TEST_SCENES
    #undef ENABLE_NO_CLIP
    #undef ENABLE_CS_CONTROL
    #undef ENABLE_FRAMERATE_OPTIONS
    #undef ENABLE_MAP_SELECT
    #undef ENABLE_INV_EDITOR
    #undef ENABLE_EVENT_EDITOR
    #undef ENABLE_REG_EDITOR
    #undef ENABLE_CAMERA_DEBUGGER
    #undef ENABLE_AUDIO_DEBUGGER
    #undef ENABLE_ACTOR_DEBUGGER
    #undef ENABLE_MSG_DEBUGGER
    #undef ENABLE_DEBUG_SAVE
    #undef MAP_SELECT_ON_FILE_1

    #define SHOW_CS_INFOS false
    #define SHOW_INPUT_DISPLAY false
    #define SHOW_TIME_INFOS false
    #define INCLUDE_TEST_SCENES false
    #define ENABLE_NO_CLIP false
    #define ENABLE_CS_CONTROL false
    #define ENABLE_FRAMERATE_OPTIONS false
    #define ENABLE_MAP_SELECT false
    #define ENABLE_INV_EDITOR false
    #define ENABLE_EVENT_EDITOR false
    #define ENABLE_REG_EDITOR false
    #define ENABLE_CAMERA_DEBUGGER false
    #define ENABLE_AUDIO_DEBUGGER false
    #define ENABLE_ACTOR_DEBUGGER false
    #define ENABLE_MSG_DEBUGGER false
    #define ENABLE_DEBUG_SAVE false
    #define MAP_SELECT_ON_FILE_1 false
#endif


// Remove actor and camera debug draw-related code if both are disabled
#ifndef NO_DEBUG_DISPLAY
    #if !ENABLE_ACTOR_DEBUGGER && !ENABLE_CAMERA_DEBUGGER
        #define NO_DEBUG_DISPLAY true
    #else
        #define NO_DEBUG_DISPLAY false
    #endif
#endif

// The camera debugger needs mempak functions for the cutscene exporter
#if ENABLE_CAMERA_DEBUGGER && !ENABLE_MEMPAK
    #undef ENABLE_MEMPAK
    #define ENABLE_MEMPAK true
#endif

// Enable the map select feature if booting to map select or using map select for file 1
#if (BOOT_TO_MAP_SELECT || MAP_SELECT_ON_FILE_1) && !ENABLE_MAP_SELECT
    #undef ENABLE_MAP_SELECT
    #define ENABLE_MAP_SELECT true
#endif

// Remove map select from file 1
#if !ENABLE_MAP_SELECT
    #undef MAP_SELECT_ON_FILE_1
    #define MAP_SELECT_ON_FILE_1 false
#endif

// The camera debugger uses the debug heap, which is located in the expanded RAM
#if ENABLE_CAMERA_DEBUGGER && !ENABLE_DEBUG_HEAP
    #undef ENABLE_DEBUG_HEAP
    #define ENABLE_DEBUG_HEAP true
#endif


/*****************
 * config_game.h
 */
#if FORCE_WIDESCREEN
    #define USE_WIDESCREEN true
#else
    #define USE_WIDESCREEN (ENABLE_WIDESCREEN && gSaveContext.save.useWidescreen == true)
#endif


/**
 * Default settings if not using HackerOoT mode
*/
#if !ENABLE_HACKEROOT
    #undef DETERMINISTIC_BUILD
    #undef SKIP_N64_BOOT_LOGO
    #undef BOOT_TO_SCENE
    #undef BOOT_TO_SCENE_NEW_GAME_ONLY
    #undef BOOT_TO_FILE_SELECT
    #undef DISABLE_DEBUG_FEATURES
    // #undef SHOW_CS_INFOS
    // #undef SHOW_INPUT_DISPLAY
    // #undef SHOW_TIME_INFOS
    #undef INCLUDE_TEST_SCENES
    // #undef ENABLE_NO_CLIP
    // #undef ENABLE_CS_CONTROL
    // #undef ENABLE_FRAMERATE_OPTIONS
    #undef ENABLE_MAP_SELECT
    // #undef ENABLE_INV_EDITOR
    // #undef ENABLE_EVENT_EDITOR
    // #undef ENABLE_REG_EDITOR
    #undef ENABLE_CAMERA_DEBUGGER
    // #undef ENABLE_AUDIO_DEBUGGER
    // #undef ENABLE_ACTOR_DEBUGGER
    // #undef ENABLE_MSG_DEBUGGER
    // #undef ENABLE_DEBUG_SAVE
    #undef MAP_SELECT_ON_FILE_1

    #define DETERMINISTIC_BUILD false
    #define SKIP_N64_BOOT_LOGO true
    #define BOOT_TO_SCENE false
    #define BOOT_TO_SCENE_NEW_GAME_ONLY false
    #define BOOT_TO_FILE_SELECT false
    #define DISABLE_DEBUG_FEATURES false
    // #define SHOW_CS_INFOS false
    // #define SHOW_INPUT_DISPLAY false
    // #define SHOW_TIME_INFOS false
    #define INCLUDE_TEST_SCENES true
    // #define ENABLE_NO_CLIP false
    // #define ENABLE_CS_CONTROL false
    // #define ENABLE_FRAMERATE_OPTIONS false
    #define ENABLE_MAP_SELECT true
    // #define ENABLE_INV_EDITOR false
    // #define ENABLE_EVENT_EDITOR false
    // #define ENABLE_REG_EDITOR false
    #define ENABLE_CAMERA_DEBUGGER true
    // #define ENABLE_AUDIO_DEBUGGER false
    // #define ENABLE_ACTOR_DEBUGGER false
    // #define ENABLE_MSG_DEBUGGER false
    // #define ENABLE_DEBUG_SAVE false
    #define MAP_SELECT_ON_FILE_1 true
#endif

#endif
