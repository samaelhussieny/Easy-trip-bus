#pragma once
#include "Busses.h"
#include "LinkedQueue.h"
#include "LinkedPriorityQueue.h"
#include "Passenger.h"
#include "MBus.h"
#include "WBus.h"
class Company;
class Stations
{
private:
	int NumWPS;
	int NumWPN;
	int NumWPW;
	int NumOfWBuses;
	int NumOfMBuses;
	int StationNum;
	int ST;
	LinkedQueue<WBus*>WBBus;
	LinkedQueue<MBus*>MBBus;
	LinkedQueue<WBus*>WFBus;
	LinkedQueue<MBus*>MFBus;
	LinkedQueue<Passenger*>FNP;
	LinkedQueue<Passenger*>BNP;
	LinkedPriorityQueue<Passenger*> FSP;
	LinkedPriorityQueue<Passenger*> BSP;
	LinkedQueue<Passenger*>BWH;
	LinkedQueue<Passenger*>FWH;
	
public:
	Stations();
	~Stations();
	void BusBordring(int getTime,Company* C,int Sn);
	bool IsEmptyFSP();
	bool IsEmptyBSP();
	bool IsEmptyFNP();
	bool IsEmptyBNP();
	bool IsEmptyBWH();
	bool IsEmptyFWH();
	void PrintBusinfo();
	void Set_NumWPs(int n);
	void Set_NumWPn(int n);
	void Set_NumWPw(int n);
	int Get_NumWPs();
	int Get_NumWPn();
	int Get_NumWPw();
	int Get_NumofMbuses();
	int Get_NumOfWbuses();
	void Set_NumofMbuses(int n);
	void Set_NumOfWbuses(int n);
	int Get_NumStations();
	void Set_NumStations(int N);
	int Get_StationTime();
	void Set_StationTime(int T);
	void InsertWFBus(WBus& Bus);
	void InsertMFBus(MBus& Bus);
	void InsertWBBus(WBus& Bus);
	void InsertMBBus(MBus& Bus);
	void InsertFNPass(Passenger* Pass);
	void InsertBNPass(Passenger* Pass);
	void InsertFSPass(Passenger* Pass);
	void InsertBSPass(Passenger* Pass);
	void InsertBWH(Passenger* Pass);
	void InsertFWH(Passenger* Pass);
	bool DeleteWFBus(WBus& Bus);
	bool DeleteMFBus(MBus& Bus);
	bool DeleteWBBus(WBus& Bus);
	bool DeleteMBBus(MBus& Bus);
	void DeleteFSPass(Passenger* Pass); 
	void DeleteBSPass(Passenger* Pass);
	void DeleteBWH(Passenger* Pass);
	void DeleteFWH(Passenger* Pass);
	void DeleteNFPass(Passenger* Pass);
	void DeleteNBPass(Passenger* Pass);
	void PrintFNP();
	void PrintFSP();
	void PrintFWP();
	void PrintBNP();
	void PrintBSP();
	void PrintBWP();
	void GetOff(int getTime, Company* C, int Sn);
	bool search(int id);
};

