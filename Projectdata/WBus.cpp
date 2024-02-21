#include "WBus.h"

bool WBus::InsertPass(Passenger& Pass)
{
	if (AcCap == BC)return false;
	Passenger* P = new Passenger(Pass);
	BusWH.enqueue(P);
	BusWH.SortingByES();
	AcCap++;
	return true;
}

bool WBus::DeletePass(Passenger& Pass,int i)
{
	Passenger* P=nullptr;
	if (AcCap == 0) return false;
	if (BusWH.isEmpty())return false;
	BusWH.peek(P);
	if (P->GetEndStat() != i) return false;
	BusWH.dequeue(P);
	Pass = *P;
	AcCap--;
	return true;
}

bool WBus::InsertPassB(Passenger& Pass)
{
	if (AcCap == BC)return false;
	Passenger* P = new Passenger(Pass);
	BusWH.enqueue(P);
	BusWH.SortingBACES();
	AcCap++;
	return true;
}

WBus::WBus()
{
	AcCap = 0;
	BC = 0;
	id = 0;
	ty = "WBus";
	STN = 0;
	Maintance = 0;
	Journeys = 0;
	T = new Time();
	T->Set_hh(4);
	T->set_mm(0);
}

WBus::WBus(int Bc, int Main, int j,int ID)
{
	BC = Bc;
	id = ID;
	Maintance = Main;
	Journeys = j;
	ty = "WBus";
	AcCap = 0;
	STN = 0;
	T = new Time();
	T->Set_hh(4);
	T->set_mm(0);
}
int WBus::Get_c()
{
	return BC;
}

void WBus::SetTime(int hh,int mm)
{
	T->Set_hh(hh);
	T->set_mm(mm);
}

Time* WBus::GetTime() 
{
	return T;
}

void WBus::setSTN(int N)
{
	STN = N;
}

int WBus::GetSTN()
{
	return STN;
}

int WBus::Get_ID()
{
	return id;
}

string WBus::Get_ty()
{
	return ty;
}

void WBus::PrintPass()
{
	BusWH.PrintId();
}

WBus::~WBus()
{
}
