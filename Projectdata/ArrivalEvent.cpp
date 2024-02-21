#include "ArrivalEvent.h"

ArrivalEvent::ArrivalEvent()  //intialization of each parameter
{
	TYP="";
	SPT="";
	ETh = 0;
	ETm = 0;
	ID = 0;
	STRT = 0;
	END = 0;
	ETh = 0;
	ETm = 0;
	E = "A";
}

void ArrivalEvent::set_hh(int h) 
{
	ETh = h;
}

void ArrivalEvent::set_mm(int m)
{
	ETm = m;
}

int ArrivalEvent::get_hh()
{
	return ETh;
}

int ArrivalEvent::get_mm()
{
	return ETm;
}

void ArrivalEvent::load(ifstream& inf,int G_T)
{
	string T;
	inf >> T;
	TYP = T;
	if (T == "NP")   //check kind of passanger
	{
		inf >> ETh;
		inf.ignore(1000, ':');  //ignore  ':'  form time as(4:6) 
		inf >> ETm >> ID >> STRT >> END;
	}
	else if (T == "SP")
	{
		inf >> ETh;
		inf.ignore(1000, ':');  //ignore  ':'  form time as(4:6) 
		inf >> ETm >> ID >> STRT >> END >> SPT;
	}
	else if (T == "WP")
	{
		inf >> ETh;
		inf.ignore(1000, ':');    //ignore  ':'  form time as(4:6) 
		inf >> ETm >> ID >> STRT >> END;
	}
	GT = G_T;  //get off/on time for every passenger
}

bool ArrivalEvent::excute(Stations *S)
{
	Passenger* P=nullptr;
	
		if ((STRT - END) > 0)    // Backward passenger
		{
			if (TYP == "NP" )  //ckeaking the type 
			{
				P = new Passenger(ETh, ETm,ID, &S[STRT], &S[END], GT, TYP,END); //create the passenger
				S[STRT].InsertBNPass(P);  // insert the passenger in its start station
			}
			else if (TYP == "SP")
			{
				P = new Passenger(ETh, ETm,ID, &S[STRT], &S[END], GT, TYP, SPT,END); //create the passenger
				S[STRT].InsertBSPass(P); // insert the passenger in its start station
			}
			else if (TYP == "WP")
			{
				P = new Passenger(ETh, ETm,ID, &S[STRT], &S[END], GT, TYP,END); //create the passenger
				S[STRT].InsertBWH(P);  // insert the passenger in its start station
			}
			
		}
		else if ((STRT - END) < 0)  // forward passenger
		{
			if (TYP == "NP")  //ckeaking the type
			{
				P = new Passenger(ETh, ETm,ID, &S[STRT], &S[END], GT, TYP,END); //create the passenger
				S[STRT].InsertFNPass(P);  // insert the passenger in its start station
			}
			else if (TYP == "SP")
			{
				P = new Passenger(ETh, ETm,ID, &S[STRT], &S[END], GT, TYP, SPT,END); //create the passenger
				S[STRT].InsertFSPass(P);  // insert the passenger in its start station
			}
			else if (TYP == "WP")
			{
				P = new Passenger(ETh, ETm,ID, &S[STRT], &S[END], GT, TYP,END); //create the passenger
				S[STRT].InsertFWH(P);  // insert the passenger in its start station
			}
		}
		return true;
}
