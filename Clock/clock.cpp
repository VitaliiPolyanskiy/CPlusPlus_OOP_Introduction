#include<windows.h>
#include<stdio.h>
#include<conio.h>

class Clock
{
	int hours = 0;
	int seconds = 0;
	int minutes = 0;

public:
	void Print()
	{
		char buf[100] = { 0 };
		sprintf_s(buf, "%2.2d:%2.2d:%2.2d", hours, minutes, seconds);
		system("cls");
		printf(buf);
	}
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
	while(true)
	{
		while(!_kbhit())
		{
			clk.Tick();
			clk.Print();
			Sleep(1000);
			system("cls");
		}
		char result = _getch();
		if(result == 't')
		{
			clk.InputTime();
		}
		else if(result == 'q')
		{
			system("cls");
			return 0;
		}
	}	

	return 0;
}