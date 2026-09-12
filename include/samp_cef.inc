#if defined _SAMP_CEF_CROSSPLATFORM_INCLUDED
    #endinput
#endif
#define _SAMP_CEF_CROSSPLATFORM_INCLUDED


/*
    SAMP CEF CrossPlatform

    Unified Pawn API for:
        - Windows PC
        - Android / SA:MP Mobile
*/


/*
    ============================================================
        PLATFORM
    ============================================================
*/

#define CEF_PLATFORM_UNKNOWN     0
#define CEF_PLATFORM_PC         1
#define CEF_PLATFORM_ANDROID    2


/*
    ============================================================
        BROWSER
    ============================================================
*/

#define CEF_DEFAULT_BROWSER_BASE_ID  50000


/*
    ============================================================
        BACKEND SELECTION
    ============================================================
*/

#if defined SAMP_CEF_MOBILE

    #include "backends/samp_cef_mobile.inc"

#else

    #include "backends/samp_cef_pc.inc"

#endif