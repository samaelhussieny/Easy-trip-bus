#pragma once
#include "Passenger.h"
#include "QueueADT.h"
#include"LinkedQueue.h"
#include"LinkedPriorityQueue.h"


class Busses
{
private:

public:
	bool virtual InsertPass(Passenger& Pass)=0;
	bool virtual DeletePass(Passenger& Pass,int i)=0;

};

