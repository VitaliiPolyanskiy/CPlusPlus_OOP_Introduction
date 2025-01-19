
class Clock
{
	int hours = 0;
	int seconds = 0;
	int minutes = 0;
public:
	int getHours()
	{
		return hours;
	}
	int getMinutes()
	{
		return minutes;
	}
	int getSeconds()
	{
		return seconds;
	}
	void setHours(int h)
	{
		hours = h % 24;
	}

	void setMinutes(int m)
	{
		minutes = m % 60;
	}

	void setSeconds(int s)
	{
		seconds = s % 60;
	}
	void Tick();
};	

void InputTime(Clock &clk);