#include<windows.h>
#include<stdio.h>
#include<conio.h>

void Tick(int &hours, int &minutes, int &seconds)
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

void InputTime(int &hours, int &minutes, int &seconds)
{
	system("cls");
	printf("Enter an hours: ");
	scanf_s("%d", &hours);
	printf("Enter a minutes: ");
	scanf_s("%d", &minutes);
	printf("Enter a seconds: ");
	scanf_s("%d", &seconds);
}

int main()
{
	int hours = 0;
	int seconds = 0;
	int minutes = 0;
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
			Tick(hours, minutes, seconds);
			char buf[100] = { 0 };
			sprintf_s(buf, "%2.2d:%2.2d:%2.2d", hours, minutes, seconds);
			system("cls");
			SetConsoleCursorPosition(handle, cur);
			printf(buf);
			Sleep(1000);
		}
		char result = _getch();
		if (result == 't')
		{
			InputTime(hours, minutes, seconds);
		}
		else if (result == 'q')
		{
			system("cls");
			return 0;
		}
	}

	return 0;
}