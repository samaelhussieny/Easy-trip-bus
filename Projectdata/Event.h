#pragma once
#include "Passenger.h"
#include "Stations.h"
class Event
{
private:
public:
	string E;
	void virtual set_hh(int h)=0;
	void virtual set_mm(int m)=0;
	int virtual get_hh()=0;
	int virtual get_mm()=0;

	void virtual load(ifstream& inf,int G_T) = 0;
	bool virtual excute(Stations* S)=0;
};

