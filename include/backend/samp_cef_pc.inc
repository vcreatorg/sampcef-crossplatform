#if defined _SAMP_CEF_PC_BACKEND_INCLUDED
    #endinput
#endif
#define _SAMP_CEF_PC_BACKEND_INCLUDED


#include <cef>


stock CEF_GetBrowserId(playerid)
{
    return CEF_DEFAULT_BROWSER_BASE_ID + playerid;
}


stock CEF_IsAvailable(playerid)
{
    return cef_player_has_plugin(playerid);
}


stock CEF_Open(
    playerid,
    const url[],
    bool:hidden = false,
    bool:focused = false
)
{
    cef_create_browser(
        playerid,
        CEF_GetBrowserId(playerid),
        url,
        hidden,
        focused
    );

    return 1;
}


stock CEF_Close(playerid)
{
    cef_destroy_browser(
        playerid,
        CEF_GetBrowserId(playerid)
    );

    return 1;
}


stock CEF_Show(playerid)
{
    cef_hide_browser(
        playerid,
        CEF_GetBrowserId(playerid),
        false
    );

    return 1;
}


stock CEF_Hide(playerid)
{
    cef_hide_browser(
        playerid,
        CEF_GetBrowserId(playerid),
        true
    );

    return 1;
}


stock CEF_Load(playerid, const url[])
{
    cef_load_url(
        playerid,
        CEF_GetBrowserId(playerid),
        url
    );

    return 1;
}


stock CEF_Focus(playerid, bool:focused)
{
    cef_focus_browser(
        playerid,
        CEF_GetBrowserId(playerid),
        focused
    );

    return 1;
}


stock CEF_Emit(
    playerid,
    const event[],
    const data[] = ""
)
{
    /*
        The original PC API uses variadic typed
        arguments. For the first unified API version,
        we intentionally expose a simple string payload.
    */

    cef_emit_event(
        playerid,
        event,
        CEFSTR(data)
    );

    return 1;
}


stock CEF_RegisterEvent(
    const event[],
    const callback[]
)
{
    cef_subscribe(
        event,
        callback
    );

    return 1;
}


stock CEF_GetPlatform(playerid)
{
    return CEF_PLATFORM_PC;
}