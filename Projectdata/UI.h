#pragma once
#include "Time.h"
#include "Company.h"
#include "Passenger.h"
class UI
{
	int t;
	Time* time;
public:
	UI();
	void Type();
	int getType();
	void Print(Company* C, Time* time);
	void PrintS(Company*C);
	void PrintSto(Company* C, Time* time);
	~UI();
};