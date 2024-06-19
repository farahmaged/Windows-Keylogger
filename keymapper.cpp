#include <sstream>
#include "keymapper.hpp"

using namespace std;

string KeyMapper::getKeyName(DWORD vkCode, DWORD scanCode, bool shiftPressed, bool capsLockToggled) {
    stringstream keyName;

    // Handle alphabetic keys differently based on Shift and Caps Lock
    if (vkCode >= 0x41 && vkCode <= 0x5A) {
        // Uppercase letters 'A'-'Z'
        bool isUpperCase = (capsLockToggled && !shiftPressed) || (!capsLockToggled && shiftPressed);
        if (!isUpperCase) {
            // Convert to lowercase if needed
            vkCode += 0x20;
        }
        keyName << static_cast<char>(vkCode);
    } else if (vkCode >= 0x30 && vkCode <= 0x39) {
        // Numeric keys '0'-'9'
        if (shiftPressed) {
            // Special characters when Shift is pressed
            switch (vkCode) {
                case 0x30:
                    keyName << ")";
                    break;
                case 0x31:
                    keyName << "!";
                    break;
                case 0x32:
                    keyName << "@";
                    break;
                case 0x33:
                    keyName << "#";
                    break;
                case 0x34:
                    keyName << "$";
                    break;
                case 0x35:
                    keyName << "%";
                    break;
                case 0x36:
                    keyName << "^";
                    break;
                case 0x37:
                    keyName << "&";
                    break;
                case 0x38:
                    keyName << "*";
                    break;
                case 0x39:
                    keyName << "(";
                    break;
                default:
                    keyName << static_cast<char>(vkCode);
                    break;
            }
        } else {
            keyName << static_cast<char>(vkCode);
        }
    } else {
        // Handle other keys normally
        switch (vkCode) {
            // Special characters
            case VK_SPACE:
                keyName << "[SPACE]";
                break;
            case VK_OEM_3:
                keyName << (shiftPressed ? "~" : "`");
                break;
            case VK_OEM_MINUS:
                keyName << (shiftPressed ? "_" : "-");
                break;
            case VK_OEM_PLUS:
                keyName << (shiftPressed ? "+" : "=");
                break;
            case VK_OEM_4:
                keyName << (shiftPressed ? "{" : "[");
                break;
            case VK_OEM_6:
                keyName << (shiftPressed ? "}" : "]");
                break;
            case VK_OEM_5:
                keyName << (shiftPressed ? "|" : "\\");
                break;
            case VK_OEM_1:
                keyName << (shiftPressed ? ":" : ";");
                break;
            case VK_OEM_7:
                keyName << (shiftPressed ? "\"" : "'");
                break;
            case VK_OEM_COMMA:
                keyName << (shiftPressed ? "<" : ",");
                break;
            case VK_OEM_PERIOD:
                keyName << (shiftPressed ? ">" : ".");
                break;
            case VK_OEM_2:
                keyName << (shiftPressed ? "?" : "\\");
                break;

                // Modifier keys
            case VK_SHIFT:
                keyName << "[SHIFT]";
                break;
            case VK_CONTROL:
                keyName << "[CTRL]";
                break;
            case VK_MENU:
                keyName << "[ALT]";
                break;

                // Number pad keys
            case VK_NUMPAD0:
                keyName << "[NUM0]";
                break;
            case VK_NUMPAD1:
                keyName << "[NUM1]";
                break;
            case VK_NUMPAD2:
                keyName << "[NUM2]";
                break;
            case VK_NUMPAD3:
                keyName << "[NUM3]";
                break;
            case VK_NUMPAD4:
                keyName << "[NUM4]";
                break;
            case VK_NUMPAD5:
                keyName << "[NUM5]";
                break;
            case VK_NUMPAD6:
                keyName << "[NUM6]";
                break;
            case VK_NUMPAD7:
                keyName << "[NUM7]";
                break;
            case VK_NUMPAD8:
                keyName << "[NUM8]";
                break;
            case VK_NUMPAD9:
                keyName << "[NUM9]";
                break;
            case VK_DECIMAL:
                keyName << "[NUM.]";
                break;
            case VK_DIVIDE:
                keyName << "[NUM/]";
                break;
            case VK_MULTIPLY:
                keyName << "[NUM*]";
                break;
            case VK_SUBTRACT:
                keyName << "[NUM-]";
                break;
            case VK_ADD:
                keyName << "[NUM+]";
                break;

                // Function keys
            case VK_F1:
                keyName << "[F1]";
                break;
            case VK_F2:
                keyName << "[F2]";
                break;
            case VK_F3:
                keyName << "[F3]";
                break;
            case VK_F4:
                keyName << "[F4]";
                break;
            case VK_F5:
                keyName << "[F5]";
                break;
            case VK_F6:
                keyName << "[F6]";
                break;
            case VK_F7:
                keyName << "[F7]";
                break;
            case VK_F8:
                keyName << "[F8]";
                break;
            case VK_F9:
                keyName << "[F9]";
                break;
            case VK_F10:
                keyName << "[F10]";
                break;
            case VK_F11:
                keyName << "[F11]";
                break;
            case VK_F12:
                keyName << "[F12]";
                break;

                // Arrow keys
            case VK_LEFT:
                keyName << "[LEFT]";
                break;
            case VK_UP:
                keyName << "[UP]";
                break;
            case VK_RIGHT:
                keyName << "[RIGHT]";
                break;
            case VK_DOWN:
                keyName << "[DOWN]";
                break;

                // Other keys
            case VK_RETURN:
                keyName << "[ENTER]";
                break;
            case VK_TAB:
                keyName << "[TAB]";
                break;
            case VK_BACK:
                keyName << "[BACKSPACE]";
                break;
            case VK_ESCAPE:
                keyName << "[ESC]";
                break;
            case VK_CAPITAL:
                keyName << "[CAPS LOCK]";
                break;
            case VK_SNAPSHOT:
                keyName << "[PRINT SCREEN]";
                break;
            case VK_SCROLL:
                keyName << "[SCROLL LOCK]";
                break;
            case VK_PAUSE:
                keyName << "[NUM LOCK]";
                break;
            case VK_INSERT:
                keyName << "[INSERT]";
                break;
            case VK_DELETE:
                keyName << "[DELETE]";
                break;
            case VK_HOME:
                keyName << "[HOME]";
                break;
            case VK_END:
                keyName << "[END]";
                break;
            case VK_PRIOR:
                keyName << "[PAGE UP]";
                break;
            case VK_NEXT:
                keyName << "[PAGE DOWN]";
                break;

                // Default case using GetKeyNameTextA for undefined keys
            default: {
                char keyNameBuffer[0x100] = {};
                GetKeyNameTextA(scanCode << 16, keyNameBuffer, sizeof(keyNameBuffer));
                keyName << keyNameBuffer;
                break;
            }
        }
    }

    return keyName.str();
}
