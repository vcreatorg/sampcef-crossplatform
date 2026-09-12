#if defined _SAMP_CEF_TYPES_INCLUDED
    #endinput
#endif
#define _SAMP_CEF_TYPES_INCLUDED


#define CEF_MAX_EVENT_NAME 64
#define CEF_MAX_EVENT_DATA 4096


stock CEF_JSON_String(
    const key[],
    const value[],
    output[],
    output_size
)
{
    format(
        output,
        output_size,
        "{\"%s\":\"%s\"}",
        key,
        value
    );

    return 1;
}


stock CEF_JSON_Int(
    const key[],
    value,
    output[],
    output_size
)
{
    format(
        output,
        output_size,
        "{\"%s\":%d}",
        key,
        value
    );

    return 1;
}


stock CEF_JSON_Float(
    const key[],
    Float:value,
    output[],
    output_size
)
{
    format(
        output,
        output_size,
        "{\"%s\":%f}",
        key,
        value
    );

    return 1;
}