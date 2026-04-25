#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include<iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>

//for special characters
#include <string>
#include <io.h>		
#include <fcntl.h>

#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "Windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
//======= lấy tọa độ x của con trỏ hiện tại =============
#pragma comment (lib, "winmm.lib")
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//0 = Black
//1 = Blue
//2 = Green
//3 = Aqua
//4 = Red
//5 = Purple
//6 = Yellow
//7 = White
//8 = Gray
//9 = Light Blue
//10 = Light Gree
//11 = Light Aqua
//12 = Light Red
//13 = Light Purple
//14 = Light Yellow
//15 = Bright White
void SetColor(WORD color)
{	
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//0 = Black
//1 = Blue
//2 = Green
//3 = Aqua
//4 = Red
//5 = Purple
//6 = Yellow
//7 = White
//8 = Gray
//9 = Light Blue
//10 = Light Gree
//11 = Light Aqua
//12 = Light Red
//13 = Light Purple
//14 = Light Yellow
//15 = Bright White
void SetColor1(int background_color, int text_color) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = background_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color);
}
WORD saved_attributes;

void SaveConsoleAttributes() {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO console_info;
	GetConsoleScreenBufferInfo(hStdout, &console_info);
	saved_attributes = console_info.wAttributes;
}

// Thiết lập lại trạng thái màu sắc trước đó
void RestoreConsoleAttributes() {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, saved_attributes);
}
void SetConsoleBackgroundColor(int colorCode) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode | (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));
}
//parameter 65001 for Vietnamese
//Ex SetConsoleOutputCP(65001);

void DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}
void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}
void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}
void NoCursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void setConsoleFontSize(int width, int height) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	fontInfo.dwFontSize.X = width;
	fontInfo.dwFontSize.Y = height;
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

void printSpecial(const wstring& a)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_WTEXT);
	wcout << a << std::endl;
}
