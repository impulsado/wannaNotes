**Title:** ILY - ScreenCapture
**Tags:** [[ILY - Easy]]
**Topics:** #CPP #GDI #ScreenCapture

---
# ILY - ScreenCapture
# SYSTIME
Windows has a default struct made to save information about date and time. 
```c++
typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME;
```
So it makes us easier to get the information for later extract whatever we prefer. 

Along with this struct, Windows also has a function called `GetLocalTime()` that we pass a pointer to a `SYSTIME` struct and the function sets the information to it.
```c++
void GetLocalTime(
  LPSYSTEMTIME lpSystemTime
);
```

# Bitmap
- Explanation:
https://youtu.be/kpHFFFu9qeU?si=W8q9Q7fSfGTCT9M6