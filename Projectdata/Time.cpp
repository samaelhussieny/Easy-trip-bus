#include "Time.h"
Time::Time()
{
	hh = 0;
	mm = 0;
}
Time::Time(int h, int m)
{
	hh = h;
	mm = m;
}
void Time::Set_hh(int hour)
{
	hh = hour;
}

void Time::set_mm(int minute)
{
	mm = minute;
}

int Time::get_hh()
{
	return hh;
}

int Time::get_mm()
{
	return mm;
}

void Time::increment_time(int s)
{
	for (int i = 0; i < s; i++)
	{
		if (mm == 59)
		{
			mm = 0;
			hh++;
		}
		else if (mm != 59)
		{
			mm++;
		}
	}
	
		
}

void Time::CalulateTimeDifference(Time time1, Time time2)
{
	if (time2.mm > time1.mm) {
		time1.mm = time1.mm + 60;
		--time1.hh;
	}

	hh = time1.hh - time2.hh;
	mm = time1.mm - time2.mm;
}

