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
    SYSTEMTIME st;  // create the struct for the system time 
	
    GetLocalTime(&st);
	
    int year = st.wYear;  // extract year from system time
	int month = st.wMonth; // extract month from system time
	int day = st.wDay; // extract year day system time
	int hour = st.wHour; // extract year hours system time
	int minute = st.wMinute; // extract minute from system time
	int second = st.wSecond; // extract secibd from system time

    string yearS = to_string(year);
	yearS += "_";
	string monthS = to_string(month);
	monthS += "-";
	string dayS = to_string(day);
	dayS += "-";
	string hourS = to_string(hour);
	hourS += "H-";
	string minuteS = to_string(minute);
	minuteS += "M-";
	string secondS = to_string(second);
	secondS += "S.jpg";

	string name;
	name = dayS+monthS+yearS+hourS+minuteS+secondS;  // create complete string of date and time

    return name;
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