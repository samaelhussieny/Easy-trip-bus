#include "Busses.h"

Busses::Busses()
{
}

Busses::~Busses()
{
}

int Busses::Get_BC()
{
	return BC;
}

int Busses::Get_MainTance()
{
	return Maintance;
}

int Busses::Get_Journeys()
{
	return Journeys;
}

void Busses::Set_Bc(int Bc)
{
	BC = Bc;
}

void Busses::Set_Maintance(int maintance)
{
	Maintance = maintance;
}

void Busses::Set_Journeys(int J)
{
	Journeys = J;
}
