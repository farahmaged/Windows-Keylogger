#ifndef KEYMAPPER_H
#define KEYMAPPER_H

#include <string>
#include <windows.h>

using namespace std;

class KeyMapper {
public:
    static string getKeyName(DWORD vkCode, DWORD scanCode, bool shiftPressed, bool capsLockToggled);
};

#endif // KEYMAPPER_H
