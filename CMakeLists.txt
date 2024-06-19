cmake_minimum_required(VERSION 3.10)
project(Windows_Keylogger)

set(CMAKE_CXX_STANDARD 17)

# Add all the source files
set(SOURCES
        main.cpp
        keyboardhook.cpp
        keymapper.cpp
        logger.cpp
        logger.cpp
)

# Create the executable
add_executable(Windows_Keylogger ${SOURCES})

# Link necessary libraries
target_link_libraries(Windows_Keylogger kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
