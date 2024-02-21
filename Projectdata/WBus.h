#pragma once
#include "Passenger.h"
#include"Busses.h"
#include "Time.h"
class WBus : public Busses
{
private:
	int BC;
	Time *T;
	int Maintance;
	int Journeys;
	int AcCap;
	int id;
	int STN;
	string ty;
	LinkedPriorityQueue<Passenger*>BusWH;
public:
	WBus();
	WBus(int Bc, int Main, int j,int ID);
	bool InsertPass(Passenger& Pass);
	bool DeletePass(Passenger& Pass,int i);
	bool InsertPassB(Passenger& Pass);
	int Get_c();
	void SetTime(int i,int mm);
	Time* GetTime();
	void setSTN(int N);
	int GetSTN();
	int Get_ID();
	string Get_ty();
	void PrintPass();
	~WBus();
};

