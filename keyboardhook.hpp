#ifndef KEYBOARDHOOK_H
#define KEYBOARDHOOK_H

#include <windows.h>
#include "logger.hpp"
#include "keymapper.hpp"

class KeyboardHook {
public:
    static LRESULT CALLBACK keyboardHook(int nCode, WPARAM wParam, LPARAM lParam);

private:
    static Logger logger;
};

#endif // KEYBOARDHOOK_H
