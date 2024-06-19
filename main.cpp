#include <windows.h>
#include "keyboardhook.hpp"

int main() {
    // Set up hook for keyboard events
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook::keyboardHook, NULL, 0);

    // Message loop to keep the program running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Clean up
    UnhookWindowsHookEx(hook);

    return 0;
}
