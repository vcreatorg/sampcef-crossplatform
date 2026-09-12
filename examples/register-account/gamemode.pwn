#include <a_samp>
#include <samp_cef>

#define EVENT_REGISTER        "account:register"
#define EVENT_REGISTER_RESULT "account:register_result"

public OnGameModeInit()
{
    CEF_RegisterEvent(
        EVENT_REGISTER,
        "OnRegisterAccount"
    );

    return 1;
}

CMD:register(playerid, params[])
{
    if (!CEF_IsAvailable(playerid))
    {
        SendClientMessage(
            playerid,
            -1,
            "CEF is not available."
        );

        return 1;
    }

    CEF_Open(
        playerid,
        "http://localhost/register-account/index.html",
        false,
        true
    );

    return 1;
}

forward OnRegisterAccount(
    playerid,
    const data[]
);

public OnRegisterAccount(
    playerid,
    const data[]
)
{
    printf(
        "[CEF] Register data: %s",
        data
    );

    CEF_Emit(
        playerid,
        EVENT_REGISTER_RESULT,
        "{\"success\":true,\"message\":\"Account successfully created!\"}"
    );

    return 1;
}