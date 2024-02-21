#pragma once
#include"Busses.h"
#include "Time.h"
class MBus :public Busses
{
private:
	int BC;
	int Maintance;
	int Journeys;
	int AcCap; 
	int STN;
	int id;
	Time* T;
	string ty;
	LinkedPriorityQueue<Passenger*> BusF;
public:
	MBus();
	MBus(int Bc,int Main,int j,int ID);
	bool InsertPass(Passenger& Pass);
	bool DeletePass(Passenger& Pass,int i);
	bool InsertPassB(Passenger& Pass);
	int Get_c();
	int Get_ID();
	void setSTN(int N);
	int GetSTN();
	Time* GetTime() ;
	void SetTime(int t,int i);
	string Get_ty();
	void PrintPass();
	~MBus();
	

};

