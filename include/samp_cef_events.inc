#if defined _SAMP_CEF_EVENTS_INCLUDED
    #endinput
#endif
#define _SAMP_CEF_EVENTS_INCLUDED


#define CEF_EVENT(%0,%1) \
    forward %1(playerid, const data[]); \
    public %1(playerid, const data[])


#define CEF_LISTEN(%0,%1) \
    CEF_RegisterEvent(%0, %1)