#pragma once
class Time
{
private:
	int hh;
	int mm;
public:
	Time();
	Time(int h, int m);
	void Set_hh(int hour);
	void set_mm(int minute);
	int get_hh();
	int get_mm();
	void increment_time(int i);
	void CalulateTimeDifference(Time time1, Time time2);

};