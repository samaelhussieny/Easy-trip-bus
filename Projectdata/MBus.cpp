#include "MBus.h"

MBus::MBus()
{
	BC = 0;
	Maintance = 0;
	Journeys = 0;
	AcCap = 0;
	 id = 0;
	ty = "MBus";
	T = new Time();
	T->Set_hh(4);
	T->set_mm(0);

}

MBus::MBus(int Bc, int Main, int j,int ID)
{
		BC = Bc;
		Maintance = Main;
		Journeys = j;
		AcCap = 0;
		id = ID;
		ty = "MBus";
		T = new Time();
		T->Set_hh(4);
		T->set_mm(0);
}

bool MBus::InsertPass(Passenger& Pass)
{
	if (AcCap == BC)return false;
	Passenger* P = new Passenger(Pass);
	BusF.enqueue(P);
	BusF.SortingByES();
	AcCap++;
	return true;
}

bool MBus::DeletePass(Passenger& Pass,int i)
{
	Passenger* P =nullptr;
	if (AcCap == 0) return false;
	if (BusF.isEmpty())return false;
	BusF.peek(P);
	if (P->GetEndStat() != i) return false;
	BusF.dequeue(P);
	Pass = *P;
	AcCap--;
	return true;
}

bool MBus::InsertPassB(Passenger& Pass)
{

	if (AcCap == BC)return false;
	Passenger* P = new Passenger(Pass);
	BusF.enqueue(P);
	BusF.SortingBACES();
	AcCap++;
	return true;
}

int MBus::Get_c()
{
	return BC;
}

int MBus::Get_ID()
{
	return id;
}

void MBus::setSTN(int N)
{
	STN = N;
}

int MBus::GetSTN()
{
	return STN;
}

Time* MBus::GetTime() 
{
	return T;
}

void MBus::SetTime(int hh,int mm)
{
	T ->Set_hh(hh);
	T->set_mm(mm);
}

string MBus::Get_ty()
{
	return ty;
}
void MBus::PrintPass()
{
	BusF.PrintId();
}

MBus::~MBus()
{
}
