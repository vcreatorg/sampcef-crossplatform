#if defined _SAMP_CEF_MOBILE_BACKEND_INCLUDED
    #endinput
#endif
#define _SAMP_CEF_MOBILE_BACKEND_INCLUDED


#include <SAMPMobileCef>


#define CEF_PLATFORM(playerid) \
    CEF_PLATFORM_ANDROID


stock CEF_SetPacketId(packetid)
{
    CefSetPacketId(packetid);
    return 1;
}


stock CEF_IsAvailable(playerid)
{
    return CefIsPlayerHasLibrary(playerid);
}


stock CEF_Open(
    playerid,
    const url[],
    bool:hidden = false,
    bool:focused = false
)
{
    /*
        Original Android backend currently manages
        one browser instance per player.

        The browser ID is therefore intentionally hidden
        from the public API.
    */

    CefInitBrowser(playerid, url);

    /*
        Mobile backend currently exposes show/hide
        separately, so apply the requested initial state
        after initialization when needed.
    */

    #if defined CEF_MOBILE_INITIAL_STATE_HANDLER

        if (hidden)
            CefHideBrowser(playerid);

        if (focused)
            CefChangeBrowserFocus(playerid, true);

    #endif

    return 1;
}


stock CEF_Close(playerid)
{
    CefDestroyBrowser(playerid);
    return 1;
}


stock CEF_Show(playerid)
{
    CefShowBrowser(playerid);
    return 1;
}


stock CEF_Hide(playerid)
{
    CefHideBrowser(playerid);
    return 1;
}


stock CEF_Load(playerid, const url[])
{
    CefSetBrowserUrl(playerid, url);
    return 1;
}


stock CEF_Focus(playerid, bool:focused)
{
    CefChangeBrowserFocus(playerid, focused);
    return 1;
}


stock CEF_Emit(
    playerid,
    const event[],
    const data[] = ""
)
{
    CefSendEvent(
        playerid,
        event,
        data
    );

    return 1;
}


stock CEF_RegisterEvent(
    const event[],
    const callback[]
)
{
    CefRegisterEventCallback(
        event,
        callback
    );

    return 1;
}


stock CEF_GetPlatform(playerid)
{
    return CEF_PLATFORM_ANDROID;
}