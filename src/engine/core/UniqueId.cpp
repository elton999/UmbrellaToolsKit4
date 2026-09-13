#include "UniqueId.h"

std::string Umbrella::UniqueId::GetId()
{
    GUID guid;
    HRESULT hCreateGuid = CoCreateGuid(&guid);

    if (FAILED(hCreateGuid))
        return "";

    wchar_t wStrBuffer[40];

    int result = StringFromGUID2(guid, wStrBuffer, 40);

    if (result == 0)
        return "";

    std::wstring wstr(wStrBuffer);
    std::string str(wstr.begin(), wstr.end());

    return str;
}
