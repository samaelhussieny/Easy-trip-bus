#include "Company.h"
#include "UI.h"
Company::Company()
{
	 S=0;
	 ST=0;
	WBus_count=0;
	MBus_count=0;
	C_WBus=0;
	C_MBus=0;
	J=0;
	H_WBus=0;
	H_MBus=0;
	maxW=0;
	GetTime=0;
	NumE=0;
	Station=nullptr;
	 NumFP=0;
	T = new Time();
	T ->Set_hh(4);
	T->set_mm(0);
	AN = 0;
	LN = 0;

	
}
void Company::InsertMovWB(WBus& Bus)
{
	WBus* P = new WBus(Bus);
	MovWBus.enqueue(P);
}
void Company::InsertMovMB(MBus& Bus)
{
	MBus* P = new MBus(Bus);
	MovMBus.enqueue(P);
}

void Company::InsertBMovWB(WBus& Bus)
{
	WBus* P = new WBus(Bus);
	MovBWBus.enqueue(P);
}

void Company::InsertBMovMB(MBus& Bus)
{
	MBus* P = new MBus(Bus);
	MovBMBus.enqueue(P);
}

void Company::InsertFPass(Passenger& Pass)
{
	Passenger* P = new Passenger(Pass);
	FnP.enqueue(P);
	NumFP++;
}
void Company::Set_NumFP(int n)
{
	NumFP = n;
}
int Company::Get_NumFP()
{
	return NumFP;
}
void Company::IncrementFL()
{
	NumFP ++;
}
void Company::PrintFIDP()
{
		FnP.PrintId();
}

void Company::Set_S(int s)
{
	S = s;
}

void Company::Set_ST(int s)
{
	ST = s;
}
bool Company::Relese(Time* T ,int STT)
{
	MBus *mBus=new MBus();
	MBus* m = nullptr;
	WBus* w = nullptr;
	WBus *wBus=new WBus() ;
	if (T->get_mm() == STT)   //check if the current time the same time that we should release bus 
	{
		while (Station[0].DeleteMFBus(*mBus))   //delete it from station zero
		{
			m = mBus;
			Station[1].InsertMFBus(*mBus);  //insert in station one
			break;
		}
		while (Station[0].DeleteWFBus(*wBus))  //delete it from station zero
		{
			w = wBus;
			Station[1].InsertWFBus(*wBus);  //insert in station one
			break;
		}
		return true; 
	}
	else 
	{
		return false;
	}
}

void Company::Set_WBus_count(int b)
{
	WBus_count = b;
}

void Company::Set_MBus_count(int b)
{
	MBus_count = b;
}

void Company::Set_C_WBus(int b)
{
	C_WBus = b;
}

void Company::Set_C_MBus(int b)
{
	C_MBus = b;
}

void Company::Set_J(int j)
{
	J = j;
}

void Company::Set_HWBus(int hb)
{
	H_WBus = hb;
}

void Company::Set_HMBus(int hb)
{
	H_MBus = hb;
}

void Company::Set_maxW(int w)
{
	maxW = w;
}

void Company::Set_NumE(int e)
{
	NumE = e;
}

int Company::Get_S()
{
	return S;
}

int Company::Get_ST()
{
	return ST;
}

int Company::Get_WBus_count()
{
	return WBus_count;
}

int Company::Get_MBus_count()
{
	return MBus_count;
}

int Company::Get_C_WBus()
{
	return C_WBus;
}

int Company::Get_C_MBus()
{
	return C_MBus;
}

int Company::Get_J()
{
	return J;
}

int Company::Get_HWBus()
{
	return H_WBus;
}

int Company::Get_HMBus()
{
	return H_MBus;
}

int Company::Get_maxW()
{
	return maxW;
}

int Company::Get_NumE()
{
	return NumE;
}

Time* Company::getTime()
{ 
	return T;
}
void Company::MovToSt()
{
	MBus* bus =nullptr;
	MBus* m = nullptr;
	while (MovMBus.peek(bus))   //if bus found
	{
		Time Bt = *(bus->GetTime());     //get time the bus released in moving list
		Bt.increment_time(ST-1);         // increment time of time duration the station 
		if ((Bt.get_hh() == T->get_hh())&&(Bt.get_mm() == T->get_mm()) )   //check if the same time that should arrive in the station
		{
			int Sn=bus->GetSTN(); //get the station the bus was in
			if (Sn == S - 1)
			{
				Station[Sn].InsertMBBus(*bus);   //if it the last station make it backward
			}
			else
			{
				Station[Sn + 1].InsertMFBus(*bus); //insert in the second station
			}
			;
			MovMBus.dequeue(m);   //delete the bus
			MovMBus.peek(bus);    //get next bus
		}
		else
		{
			break;
		}
		
	}
	WBus* w=nullptr;
	WBus* wbus = nullptr;
	while (MovWBus.peek(wbus))  //if bus found
	{
		Time Btt = *(wbus->GetTime());   //get time the bus released in moving list
		Btt.increment_time(ST-1);      // increment time of time duration the station 
		if ((Btt.get_hh() == T->get_hh()) && (Btt.get_mm() == T->get_mm()))  //check if the same time that should arrive in the station
		{
			int Sn = wbus->GetSTN();   //get the station the bus was in
			if (Sn == S - 1)
			{
				Station[Sn].InsertWBBus(*wbus);  //if it the last station make it backward
			}
			else
			{
               Station[Sn+1].InsertWFBus(*wbus);  //insert in the second station
			}
			
			MovWBus.dequeue(w);   //delete the bus
			MovWBus.peek(wbus);    //get next bus
		}
		else
		{
			break;
		}
	}

	MBus* Bbus = nullptr;
	MBus* Bm = nullptr;
	while (MovBMBus.peek(Bbus))  //if bus found
	{
		Time Bt = *(Bbus->GetTime());   //get time the bus released in moving list
		Bt.increment_time(ST - 1);     // increment time of time duration the station 
		if ((Bt.get_hh() == T->get_hh()) && (Bt.get_mm() == T->get_mm()))  //check if the same time that should arrive in the station
		{
			int Sn = Bbus->GetSTN();  //get the station the bus was in
			if (Sn == 1)
			{
				Station[Sn].InsertMFBus(*Bbus);  //if it the first station make it forward
			}
			else
			{
				Station[Sn - 1].InsertMBBus(*Bbus);  //insert in the second station
			}
			;
			MovBMBus.dequeue(Bm);  //delete the bus
			MovBMBus.peek(Bbus);    //get next bus
		}
		else
		{
			break;
		}

	}
	WBus* Bw = nullptr;
	WBus* Bwbus = nullptr;
	while (MovBWBus.peek(Bwbus))  //if bus found
	{
		Time Btt = *(Bwbus->GetTime());   //get time the bus released in moving list
		Btt.increment_time(ST - 1);     // increment time of time duration the station 
		if ((Btt.get_hh() == T->get_hh()) && (Btt.get_mm() == T->get_mm()))  //check if the same time that should arrive in the station
		{
			int Sn = Bwbus->GetSTN();  //get the station the bus was in
			if (Sn == 1)
			{
				Station[Sn].InsertWFBus(*Bwbus);   //if it the first station make it forward
			}
			else
			{
				Station[Sn - 1].InsertWBBus(*Bwbus);  //insert in the second station
			}

			MovBWBus.dequeue(Bw);  //delete the bus
			MovBWBus.peek(Bwbus);   //get next bus
		}
		else
		{
			break;
		}
	}
}
Stations* Company::GetStation()
{
	return Station;
}
void Company::Simulate(string file)
{

	UI* temp = new UI;  //create UI to print and type
	LoadFile(file);     // load file
	int STT = ST;       
	temp->Type();       //check if interactive  or silent mode
	while (!((T->get_hh() == 23) && (T->get_mm() == 59))) //while if we still in the office hours
	{
		Event* Ev = nullptr;
		if (Events.peek(Ev))  //if still there is events
		{
			while ((Ev->get_hh() == T->get_hh()) && (Ev->get_mm() == T->get_mm())) //if the events time equals the time of the program 
			{
				Events.dequeue(Ev); //dequeue events 
				if (Ev->excute(Station))  //excute the event
				{
					if (Ev->E == "L")  //check if the excute of the leave acutually happens increase leave number
						LN++;
				}
				if(!(Events.peek(Ev)))break;    
			}

		}
			if (Relese(T, STT))  //release bus every 15 min
			{
				STT = STT + 15;   //increase time according to the last releasing
			}
		
			temp->Print(this, T);   //printing stations
 			Bordring(T);            //bordring and unbordring
			MovToSt();              //moving buses form moving to waiting
			if (NumFP==(AN - LN))   //if finised passengers equal the passanger that arrive minus the acutually leaving close the program
				break;
			T->increment_time(1);
    }
	while (!(NumFP == (AN - LN)))  //if still there is passenger on buses after the office hours 
	{
		temp->Print(this, T);
		GETOF();                  //get them of without bordring any other passenger
		MovToSt();               //move the buses
		T->increment_time(1);
	}
	BusToZero();                 //return buses to zero station
	T->increment_time(1);
	temp->PrintSto(this,T);     //print the station zero after the office hours
	Save();
	if (temp->getType() == 2)
		temp->PrintS(this);
	
}

void Company::GETOF()
{
	for (int i = 0; i < S; i++)
	{
		Station[i].GetOff(GetTime, this, i);
	}
}

void Company::BusToZero()
{
	
	for (int i = 1; i < S; i++)
	{
		MBus* Bus = new MBus();
		while (Station[i].DeleteMBBus(*Bus))
		{
			Station[0].InsertMBBus(*Bus);
		}
		MBus* bus = new MBus();
		while (Station[i].DeleteMFBus(*bus))
		{
			Station[0].InsertMFBus(*bus);
		}
		WBus* wBus = new WBus();
		while (Station[i].DeleteWBBus(*wBus))
		{
			Station[0].InsertWBBus(*wBus);
		}
		WBus* wbus = new WBus();
		while (Station[i].DeleteWFBus(*wbus))
		{
			Station[0].InsertWFBus(*wbus);
		}
	}
	WBus* b = new WBus();
	while (MovWBus.dequeue(b))
	{
		Station[0].InsertWFBus(*b);
	}
	MBus* s = new MBus();
	while (MovMBus.dequeue(s))
	{
		Station[0].InsertMFBus(*s);
	}
	WBus* n = new WBus();
	while (MovBWBus.dequeue(n))
	{
		Station[0].InsertWBBus(*n);
	}
	MBus* m = new MBus();
	while (MovBMBus.dequeue(m))
	{
		Station[0].InsertMBBus(*m);
	}
}

void Company ::Bordring(Time* T)
{
		for (int i = 1; i < S; i++)
		{
       		Station[i].BusBordring(GetTime, this,i);
		}
}

bool Company::IsSimuOver()
{
	return true;
}

void Company::Save()
{
	ofstream OutputFile;
	Passenger* Pass = nullptr;
	OutputFile.open("output6.txt", ios::out);
	OutputFile << "FT       " << "ID       " << "AT       " << "WT       " <<"TT\n";
    while(FnP.dequeue(Pass))
	{
		OutputFile << Pass->GetFTh() << ":" << Pass->GetFTm() << "      " << Pass->Get_ID() << "        " << Pass->Get_ATH() << ":" << Pass->Get_ATM() << "      " << Pass->GetWTh() << ":" << Pass->GetWTm() << "     " << Pass->GetTTh() << ":" << Pass->GetTTm()<<"\n";
	}
	OutputFile << "Passengers: " << NumFP <<"\n";
	OutputFile << "Buses: " << WBus_count + MBus_count << " [WBus :" << WBus_count << ", MBus :" << MBus_count << "]\n";
	OutputFile.close();
}

Company::~Company()
{
	if (Station->Get_NumStations() == S)
	{
		delete[]Station;

	}

}

void Company::LoadFile(string file)
{
 ifstream inf;   

 inf.open(file);  //open the file 

 int NumS = 0, STme=0;
  inf >> NumS>> STme;   //get num of stations ,get time between every station
  ST = STme;
  NumS++;
  S = NumS;            // increase num of station by 1 for station zero
  Station = new Stations[NumS];    //create an array for num of stations
  
  int WBusC=0,MBusC=0,CMB=0,CWB=0,j=0,HMB=0,HWB=0;
  inf >> WBusC  >> MBusC;    //get number of wheel chair buses and mixed buses 
  inf >> CWB >> CMB;         //get the capacity of each type
  inf >> j >> HWB >> HMB;    //get num of trips before checkup ,and the cheekup duration for each type
  WBus_count = WBusC;     
  MBus_count = MBusC;
  C_MBus = CMB;
  C_WBus = CWB;
  J = j;
  H_MBus = HMB;
  H_WBus = HWB;      //store every variable in the variables of company
  for (int i = 0; i < NumS; i++)  //set the time between every station in each station
  {
	  Station[i].Set_StationTime(STme);
  }

  for (int i = 0; i < WBusC; i++)   //create mixed buses and set them in station zero
  {
	  WBus* Bus = new WBus(CWB, HWB, j,i+1);

	  Station[0].InsertWFBus(*Bus);
  }
  for (int i = 0; i < MBusC; i++)   //create Wheel chair buses and set them in station zero
  {
	  MBus* Bus = new MBus(CMB, HMB, j,i+1);
	 
	  Station[0].InsertMFBus(*Bus);
  }
  inf >> maxW >> GetTime;  //get maxium time wait  ,get time off/on
  int Num = 0;
  inf >> Num;
  NumE = Num;
  string E;
  Event* Evnt = NULL;  
  for (int i = 0; i < Num; i++)  //loading every event in the file
  {
	inf >> E;

	if (E == "A")
	{
		Evnt = new ArrivalEvent();
		Evnt->load(inf,GetTime); //if it is an arrival event call function load from arrival class 
		  AN++;                  //counting every arival event
		Events.enqueue(Evnt);    //insert in the queue of events
	}
	else if (E == "L")
	{
		Evnt = new LeaveEvent();
		Evnt->load(inf,GetTime);  //if it is an leave event call function load from leave class
		Events.enqueue(Evnt);     //insert in the queue of events
	}
  }
}




