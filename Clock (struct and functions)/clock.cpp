#include<windows.h>
#include<stdio.h>
#include<conio.h>

struct Clock
{
	int hours = 0;
	int seconds = 0;
	int minutes = 0;
};

void Tick(Clock & clk)
{
	clk.seconds++;
	if (clk.seconds > 59)
	{
		clk.seconds = 0;
		clk.minutes++;
		if (clk.minutes > 59)
		{
			clk.minutes = 0;
			clk.hours++;
			if (clk.hours > 23)
			{
				clk.hours = 0;
			}
		}
	}
}

void InputTime(Clock & clk)
{
	system("cls");
	printf("Enter an hours: ");
	scanf_s("%d", &clk.hours);
	printf("Enter a minutes: ");
	scanf_s("%d", &clk.minutes);
	printf("Enter a seconds: ");
	scanf_s("%d", &clk.seconds);
}

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
			Tick(clk);
			char buf[100] = { 0 };
			sprintf_s(buf, "%2.2d:%2.2d:%2.2d", clk.hours, clk.minutes, clk.seconds);
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