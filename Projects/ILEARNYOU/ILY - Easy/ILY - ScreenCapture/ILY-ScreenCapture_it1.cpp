#include <iostream>
#include <windows.h>
#include <gdiplus.h>
#include <filesystem>
#include <string>

using namespace std;
using namespace Gdiplus;
namespace fs = std::filesystem;

// Inicializa GDI+
void InitGDIPlus() {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

// Realiza la captura de pantalla y la guarda en un archivo
void CaptureScreen(const wstring& filePath) {
    // Obtiene el tamaño de la pantalla
    int screenX = GetSystemMetrics(SM_CXSCREEN);
    int screenY = GetSystemMetrics(SM_CYSCREEN);

    // Crea un DC compatible con la pantalla
    HDC hScreenDC = GetDC(NULL);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, screenX, screenY);
    SelectObject(hMemoryDC, hBitmap);

    // Copia la pantalla al DC de memoria
    BitBlt(hMemoryDC, 0, 0, screenX, screenY, hScreenDC, 0, 0, SRCCOPY);

    // Inicializa GDI+
    InitGDIPlus();

    // Crea el bitmap GDI+ a partir del HBITMAP
    Bitmap bitmap(hBitmap, NULL);

    // Guarda el bitmap como archivo JPG
    CLSID clsid;
    CLSIDFromString(L"{557CF401-1A04-11D3-9A73-0000F81EF32E}", &clsid); // CLSID para JPG
    bitmap.Save(filePath.c_str(), &clsid, NULL);

    // Libera recursos
    DeleteObject(hBitmap);
    DeleteDC(hMemoryDC);
    ReleaseDC(NULL, hScreenDC);
}

/**
 * @brief
 * 
 * @pre True
 * @post Returns a string with the fileName formated with time-hour
 */
string createName() {
    SYSTEMTIME st;  // Creates a struct for the information
    GetLocalTime(&st);
    
    string yearS = to_string(st.wYear) + "_";
    string monthS = to_string(st.wMonth) + "-";
    string dayS = to_string(st.wDay) + "-";
    string hourS = to_string(st.wHour) + "H-";
    string minuteS = to_string(st.wMinute) + "M-";
    string secondS = to_string(st.wSecond) + "S";
    string extensionS = ".jpg";

    return dayS + monthS + yearS + hourS + minuteS + secondS + extensionS;
}

// g++ .\ILY-ScreenCapture_it1.cpp -o .\ILY-ScreenCapture_it1.exe -lgdi32 -lgdiplus -lole32
int main() {
    // Folder for the screenshots configuration
    string folder = "screenshots";
    fs::create_directory(folder);
    
    while (true) {
        // Create screenshot name
        string name = createName();
        string fullname = ".\\" + folder + "\\" + name;
        wstring filePath;
        filePath.assign(fullname.begin(), fullname.end());  // string to wstring
        
        // Take the screenshot and save it
        CaptureScreen(filePath);
        
        // Set the execution delay
        Sleep(1000*30);
    }

    return 0;
}