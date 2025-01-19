#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include "Clock.h"

int main()
{
	Clock clk;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cur;
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 10;
	SetConsoleCursorInfo(handle, &info);
	cur.X = 36;
	cur.Y = 10;
	while (true)
	{
		while (!_kbhit())
		{
			clk.Tick();
			char buf[100] = { 0 };
			int h = clk.getHours();
			int m = clk.getMinutes();
			int s = clk.getSeconds();
			sprintf_s(buf, "%2.2d:%2.2d:%2.2d", h, m, s);
			system("cls");
			SetConsoleCursorPosition(handle, cur);
			printf(buf);
			Sleep(1000);
		}
		char result = _getch();
		if (result == 't')
		{
			InputTime(clk);
		}
		else if (result == 'q')
		{
			system("cls");
			return 0;
		}
	}

	return 0;
}