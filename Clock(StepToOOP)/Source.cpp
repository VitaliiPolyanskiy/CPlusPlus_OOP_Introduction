#include<windows.h>
#include<stdio.h>
#include<conio.h>

struct Clock
{
	int hours = 0;
	int seconds = 0;
	int minutes = 0;

	void Tick()
	{
		seconds++;
		if (seconds > 59)
		{
			seconds = 0;
			minutes++;
			if (minutes > 59)
			{
				minutes = 0;
				hours++;
				if (hours > 23)
				{
					hours = 0;
				}
			}
		}
	}

	void InputTime()
	{
		system("cls");
		printf("Enter an hours: ");
		scanf_s("%d", &hours);
		printf("Enter a minutes: ");
		scanf_s("%d", &minutes);
		printf("Enter a seconds: ");
		scanf_s("%d", &seconds);
	}
};

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
			sprintf_s(buf, "%2.2d:%2.2d:%2.2d", clk.hours, clk.minutes, clk.seconds);
			system("cls");
			SetConsoleCursorPosition(handle, cur);
			printf(buf);
			Sleep(1000);
		}
		char result = _getch();
		if (result == 't')
		{
			clk.InputTime();
		}
		else if (result == 'q')
		{
			system("cls");
			return 0;
		}
	}

	return 0;
}