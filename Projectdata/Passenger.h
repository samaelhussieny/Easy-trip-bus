#pragma once

#include <iostream>
using namespace std;
#include "Time.h"
#include <string.h>
class Stations;
class Passenger
{
private:
	int ATH, ATM,ID, NUMofPRI;
	Stations* Strt_Station;
	Stations* End_Station;
	int GetOnOffTime;
	string PassType;
	string SPT;
	int END;
	Time *TT;
	Time *WT;
	Time *MT;
	Time *FT;


public:
	Passenger();
	Passenger(int ATH,int ATM,int id, Stations* Strt_Station,Stations* End_Station,int GetOnOffTime ,string PassType, string PT,int end);
	Passenger(int ATH, int ATM,int id, Stations* Strt_Station, Stations* End_Station, int GetOnOffTime, string PassType,int end);
	~Passenger();
	Stations* Get_Strt_Station();
	Stations* Get_End_Station();
	int Get_GetOnOffTime();
	int GetNUMofPRI();
	int GetEndStat();
	int Get_ID();
	void Set_ID(int id);
	int Get_ATH();
	int Get_ATM();
	void CalTT();
	void CalWT();
	void SetFT(int h, int m);
	void SetMT(int h, int m);
	int GetTTh();
	int GetWTh();
	int GetFTh();
	int GetMTh();
	int GetTTm();
	int GetWTm();
	int GetFTm();
	int GetMTm();
	void Set_Strt_Station(Stations* Strt);
	void Set_End_Station(Stations* End);
	void Set_GetOnOffTime(int OnOffTime);
	void Set_PassengerType(string Type);
	void Set_Pass_SP(string SP);
	void Set_ATH(int Ath);
	void Set_ATM(int Atm);
	string Get_PassengerType();
	string Get_Pass_SP();
};
