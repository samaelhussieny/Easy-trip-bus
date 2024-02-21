#pragma once
#include <cstdlib>
#include <ctime>
#include"LinkedList.h"
#include<iostream>
#include "MBus.h"
#include "WBus.h"
#include "Busses.h"
#include "Event.h"
#include "ArrivalEvent.h"
#include "LeaveEvent.h"
#include"Time.h"
#include "Passenger.h"
#include "Stations.h"
#include <fstream>
class UI;
class Company
{
	Time* T;     //time of the program
	int S;       //num of the station
	int ST;      // time between each station
	int WBus_count;  //num of wheel chair buses
	int MBus_count;  //num of mixed buses
	int C_WBus;      //capacity of each wheel chair bus
	int C_MBus;      //capacity of each mixed bus
	int J;           //num of trips before checkup
	int H_WBus;      //time of maintance of wheel chair buses
	int H_MBus;      //time of maintance of Mixed buses
	int maxW;        //maximum time of waiting
	int GetTime;     //get off/on time
	int NumE;        //num of events
	int AN;          //number of arrival events
	int LN;          //number of leave events
	LinkedQueue<Event*> Events;    //queue of all events
	Stations* Station;    //array of stations
	int NumFP;           //num of finished passangers
	LinkedQueue<Busses*>ChkUp;    //queue for checkup buses
	LinkedQueue<WBus*>MovWBus;    //queue for wheel chair moving buses forward
	LinkedQueue<MBus*>MovMBus;	  //queue for Mixed moving buses forward
	LinkedQueue<WBus*>MovBWBus;	  //queue for wheel chair moving buses backward
	LinkedQueue<MBus*>MovBMBus;	  //queue for Mixed moving buses bacward
	LinkedQueue<Passenger*> FnP;  //queue for finished passanger
public:
	Company();
	void InsertMovWB(WBus& Bus);       //insert moving wheel chair bus forward
	void InsertMovMB(MBus& Bus);	   //insert moving mixed bus forward
	void InsertBMovWB(WBus& Bus);	   //insert moving wheel chair bus backward
	void InsertBMovMB(MBus& Bus);	   //insert moving mixed bus backward
	void InsertFPass(Passenger& Pass); //insert finished passenger
	void Set_NumFP(int n);			   //set number of finished passenger
	void IncrementFL();				   // increment number of finished passngers
	void PrintFIDP();				   //print finised passangers id
	int Get_NumFP();				   // get number of finished passengers
	void Bordring(Time* T);			   // call func bordring and unbordring the passanger form the station class
	void Set_S(int s);				   
	void Set_ST(int s);				   
	bool Relese(Time* T,int STT);	   //relese buses from zero station every 15 min
	void Set_WBus_count(int b);		   
	void Set_MBus_count(int b);		   
	void Set_C_WBus(int b);			   
	void Set_C_MBus(int b);			   
	void Set_J(int j);				   
	void Set_HWBus(int hb);			   
	void Set_HMBus(int hb);			   
	void Set_maxW(int w);			   
	void Set_NumE(int e);			   
	int Get_S();					   
	int Get_ST();					   
	int Get_WBus_count();			   
	int Get_MBus_count();			   
	int Get_C_WBus();				   
	int Get_C_MBus();				   
	int Get_J();					   
	int Get_HWBus();				   
	int Get_HMBus();				   
	int Get_maxW();					   
	int Get_NumE();					   
	Time *getTime();				   
	void MovToSt();					   //moving bus from moving list to waiting in station bus
	Stations* GetStation();			   
	void LoadFile(string file);		   //loading the file 
	void Simulate(string file);		   //simulate the program
	void GETOF();					   //getting passengers off from the buses
	void BusToZero();				   //return buses to station zero
	bool IsSimuOver();				   //if simulation is over
	void Save();
	~Company();
};

