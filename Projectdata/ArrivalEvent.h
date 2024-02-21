#pragma once
#include <iostream>
using namespace std;
#include "Event.h"
#include <string>
#include<fstream>
class ArrivalEvent : public Event
{
public:
	string TYP;     // type of passanger  (normal ,special,wheel chair)
	int ETh;        // time of event in hours
	int ETm;        // time of event in min  
	int ID;         // id of the passenger  
	int STRT;       // start station of the passenger
	int END;        //end station of the passenger
	string SPT;     // type of special (preg, aged,POD)
	int GT;         // get off/in time
	ArrivalEvent(); // default constractor
	void set_hh(int h);   //set time of event hours
	void set_mm(int m);   //set time of event min
	int get_hh();         //get time of event hours
	int get_mm();         //get time of event min
	
	void load(ifstream& inf,int G_T);   //load every event
	bool excute(Stations *S);           //excute every event in its time
	
};

