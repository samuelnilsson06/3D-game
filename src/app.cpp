#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string> 


#include "game.h"


int sizex = 120;
int sizey = 30;

vec2 ScreenSize = vec2(sizex, sizey);

float fPlayerX = 14.7f;
float fPlayerY = 5.09f;

int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[ScreenSize.x * ScreenSize.y];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	

	// Create Map of world space # = wall block, . = space
	std::wstring map;
	map += L"#########.......";
	map += L"#...............";
	map += L"#.......########";
	map += L"#..............#";
	map += L"#......##......#";
	map += L"#......##......#";
	map += L"#..............#";
	map += L"###............#";
	map += L"##.............#";
	map += L"#......####..###";
	map += L"#......#.......#";
	map += L"#......#.......#";
	map += L"#..............#";
	map += L"#......#########";
	map += L"#..............#";
	map += L"################";

	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions


	MoveWindow(console, 0, 0, ScreenSize.x*8, ScreenSize.y*16, TRUE);

	while (true)
	{
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float deltaTime = elapsedTime.count();

		vec2 ConsoleSize = GetConsoleSize();

		for (int y = 0; y < ScreenSize.y; y++)
		{
			
			for (int x = 0; x < ScreenSize.x; x++)
			{
				if (y == ScreenSize.y-1)
					screen[y * ScreenSize.x + x] = 'X';
				else
					screen[y * ScreenSize.x + x] = '.';
			}
		}

		swprintf_s(screen, sizeof(L"%3.2f", (DOUBLE)ScreenSize.y), L"%3.2f", (DOUBLE)ScreenSize.y);

		// Display Frame
		screen[ScreenSize.x * ScreenSize.y - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, ScreenSize.x * ScreenSize.y, { 0,0 }, &dwBytesWritten);
	}

	return 0;
}