#include<windows.h>
#include<stdio.h>
#include "Clock.h"

void Clock::Tick()
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

void InputTime(Clock &clk)
{
	system("cls");
	printf("Enter an hours: ");
	int hours;
	scanf_s("%d", &hours);
	clk.setHours(hours);
	printf("Enter a minutes: ");
	int minutes;
	scanf_s("%d", &minutes);
	clk.setMinutes(minutes);
	printf("Enter a seconds: ");
	int seconds;
	scanf_s("%d", &seconds);
	clk.setSeconds(seconds);
}

