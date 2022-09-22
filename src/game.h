#include <iostream>
#include <chrono>

#include <Windows.h>

class vec2
{
public:
	int x;
	int y;
	vec2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

vec2 GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return vec2(x, y);
}

vec2 GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
	return vec2(horizontal, vertical);
}