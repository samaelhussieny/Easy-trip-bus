#pragma once
#include <iostream>
using namespace std;
#include "Event.h"
#include <string>
#include<fstream>
class LeaveEvent :public Event
{
public:
	int LTh;
	int LTm;
	int ID;
	int STRT;
	int GT;
	LeaveEvent();
	void set_hh(int h);
	void set_mm(int m);
	int get_hh();
	int get_mm();
	void load(ifstream& inf,int G_T);
	bool excute(Stations * S);
	
};

