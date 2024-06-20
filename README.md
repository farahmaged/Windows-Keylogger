# Windows Keylogger

This repository hosts the code and necessary resources for a Windows keylogger application designed to capture and log keystrokes.

## Project Overview

The main goal of this project is to create a keylogger that captures and logs keystrokes on a Windows system. Key features and components of the project include:

- Logging of all keystrokes to a file with timestamps.
- Differentiation between various key states (Shift, Caps Lock).
- Handling of special keys and modifier keys.
- Utilization of Windows API functions to capture keyboard events.

## Repository Contents

This repository contains the following files and directories:

Files:
1. `keyboardhook.h` and `keyboardhook.cpp`: Responsible for setting up and managing the keyboard hook.
2. `keymapper.h` and `keymapper.cpp`: Responsible for converting virtual key codes to their string representations.
3. `logger.h` and `logger.cpp`: Responsible for logging keystrokes to a file.
4. `main.cpp`: The main entry point of the application that sets up the keyboard hook and starts the message loop.
5. `CMakeLists.txt`: The CMake build configuration file for the project.
6. `.gitignore`: Specifies files and directories to be ignored by Git.

## Requirements

Ensure you have the following dependencies installed:

- Windows OS
- C++ compiler (e.g., MinGW, MSVC)
- CMake
- Windows API headers (included with Windows SDK)

## Security Considerations

- Keylogging can pose privacy and security risks, including the potential for data theft and unauthorized access to sensitive information.
- Use this software only on devices you own or have explicit permission to monitor.
