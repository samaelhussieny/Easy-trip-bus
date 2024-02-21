#include "LeaveEvent.h"

LeaveEvent::LeaveEvent()
{
	LTh = 0;
	LTm = 0;
	ID = 0;
	STRT = 0;
	GT = 0;
	E = "L";
}

void LeaveEvent::set_hh(int h)
{
	LTh = h;
}

void LeaveEvent::set_mm(int m)
{
	LTm = m;
}

int LeaveEvent::get_hh()
{
	return LTh;
}

int LeaveEvent::get_mm()
{
	return LTm;
}

void LeaveEvent::load(ifstream& inf,int G_T)
{
	inf >> LTh;
	inf.ignore(1000, ':');
	inf >> LTm >> ID >> STRT;
	GT = G_T;
}

bool LeaveEvent::excute(Stations * S)
{
	if (S[STRT].search(ID))
		return true;
}
