#include "Stations.h"
#include "Company.h"
Stations::Stations()
{
	 NumWPS=0;
	 NumWPN=0;
	 NumWPW=0;
	 NumOfWBuses=0;
	 NumOfMBuses=0;
	 StationNum=0;
	 ST=0;
	
}

Stations::~Stations()
{
}

void Stations::PrintBusinfo()
{
	MFBus.PrintBus("FWD");
	MBBus.PrintBus("BCK");
	WFBus.PrintBus("FWD");
	WBBus.PrintBus("BCK");
}
bool Stations::IsEmptyFSP()
{
	return FSP.isEmpty();
}
bool Stations::IsEmptyBSP()
{
	return BSP.isEmpty();
}
bool Stations::IsEmptyFNP()
{
	return FNP.isEmpty();
}
bool Stations::IsEmptyBNP()
{
	return BNP.isEmpty();
}
bool Stations::IsEmptyBWH()
{
	return BWH.isEmpty();
}
bool Stations::IsEmptyFWH()
{
	return FWH.isEmpty();
}
void Stations::Set_NumWPs(int n)
{
	NumWPS = n;
}

void Stations::Set_NumWPn(int n)
{
	NumWPN = n;
}

void Stations::Set_NumWPw(int n)
{
	NumWPW = n;
}

int Stations::Get_NumWPs()
{
	return NumWPS;
}

int Stations::Get_NumWPn()
{
	return NumWPN;
}
int Stations::Get_NumWPw()
{
	return NumWPW;
}
int Stations::Get_NumofMbuses()
{
	return NumOfMBuses;
}

int Stations::Get_NumOfWbuses()
{
	return NumOfWBuses;
}

void Stations::Set_NumofMbuses(int m)
{
	 NumOfMBuses = m;
}

void Stations::Set_NumOfWbuses(int w)
{
	NumOfWBuses = w;
}

int Stations::Get_NumStations()
{
	return ST;
}

int Stations::Get_StationTime()
{
	return ST;
}
void Stations::Set_NumStations(int N)
{
	 StationNum = N;
}

void Stations::Set_StationTime(int T)
{
	 ST = T;
}

void Stations::InsertWFBus(WBus& Bus)
{
	WBus* B = new WBus(Bus);
	WFBus.enqueue(B);
	NumOfWBuses++;
}

void Stations::InsertMFBus(MBus& Bus)
{
	MBus* B = new MBus(Bus);
	MFBus.enqueue(B);
	NumOfMBuses++;
}
void Stations::InsertWBBus(WBus& Bus)
{
	WBus* B = new WBus(Bus);
	WBBus.enqueue(B);
	NumOfWBuses++;
}

void Stations::InsertMBBus(MBus& Bus)
{
	MBus* B = new MBus(Bus);
	MBBus.enqueue(B);
	NumOfMBuses++;
}

void Stations::InsertFNPass(Passenger* Pass)
{
	FNP.enqueue(Pass);
	NumWPN++;
}

void Stations::InsertBNPass(Passenger* Pass)
{
	BNP.enqueue(Pass);
	NumWPN++;
}

void Stations::InsertFSPass(Passenger* Pass)
{
	FSP.enqueue(Pass);
	FSP.SortingByTYP();
		NumWPS++;
}

void Stations::InsertBSPass(Passenger* Pass)
{
	BSP.enqueue(Pass);
	BSP.SortingByTYP();
		NumWPS++;
}

void Stations::InsertBWH(Passenger* Pass)
{
	BWH.enqueue(Pass);
		NumWPW++;
}

void Stations::InsertFWH(Passenger* Pass)
{
	FWH.enqueue(Pass);
	NumWPW++;
}

bool Stations::DeleteWFBus(WBus& Bus)
{
	WBus* W=nullptr;
	if (NumOfWBuses == 0)
		return false;
    if(	WFBus.dequeue(W))
	{
		NumOfWBuses--;
		Bus = *W;
		return true;
	}
    else
    {
		return false;
    }
}

bool Stations::DeleteMFBus(MBus& Bus)
{
	MBus* M=nullptr;
	if (MFBus.dequeue(M)) {
		NumOfMBuses--;
		Bus = *M;
		return true;
	}
	else
	{
		return false;
	}
}
bool Stations::DeleteWBBus(WBus& Bus)
{
	WBus* W = nullptr;
	if (NumOfWBuses == 0)
		return false;
	if (WBBus.dequeue(W))
	{
		NumOfWBuses--;
		Bus = *W;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stations::DeleteMBBus(MBus& Bus)
{
	MBus* M = nullptr;
	if (MBBus.dequeue(M)) {
		NumOfMBuses--;
		Bus = *M;
		return true;
	}
	else
	{
		return false;
	}
}

void Stations::DeleteFSPass(Passenger* Pass)
{
		if (FSP.dequeue(Pass))
				NumWPS--;
}


void Stations::DeleteBSPass(Passenger* Pass)
{
		if (BSP.dequeue(Pass))
			NumWPS--;
}

void Stations::DeleteBWH(Passenger* Pass)
{
	if (NumWPW == 0)
		return;
	if(BWH.dequeue(Pass))
	NumWPW--;
}

void Stations::DeleteFWH(Passenger* Pass)
{
	if (NumWPW == 0)
		return;
	if(FWH.dequeue(Pass))
	NumWPW--;
	
}

void Stations::DeleteNFPass(Passenger* Pass)
{
	if (NumWPN == 0)
		return;
	FNP.dequeue(Pass);
	NumWPN--;
}

void Stations::DeleteNBPass(Passenger* Pass)
{
	if (NumWPN == 0)
		return;
	FNP.dequeue(Pass);
	NumWPN--;
}

void Stations::PrintFNP()
{
	FNP.PrintId();
}

void Stations::PrintFSP()
{
	FSP.PrintId();
}

void Stations::PrintFWP()
{
	FWH.PrintId();
}

void Stations::PrintBNP()
{
	BNP.PrintId();
}

void Stations::PrintBSP()
{
	BSP.PrintId();
}

void Stations::PrintBWP()
{
	BWH.PrintId();
}

void Stations::GetOff(int getTime, Company* C, int SN)
{
	const int NuPass= floor(60 / getTime);
	//For forward Mixed Passangers
	MBus* Bus = nullptr;
	Passenger* Pass = new Passenger();
	int PNPM = NuPass;       //Number of passengers per min
	while (MFBus.peek(Bus)) //if the bus found
	{
        while (PNPM > 0)  //While get off/on in the same min 
		{
		
  			if (Bus->DeletePass(*Pass,SN))  //if there is a pass arrive to his final destnation
			{
				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
              C->InsertFPass(*Pass);     //insert inside finish list in the company
				PNPM--;

			}
			else
			{
				
				if (MFBus.dequeue(Bus))    //if the capacity full dequeue
				{
					Bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());  //set time that the bus leave the station
					NumOfMBuses--;
					Bus->setSTN(SN);   //set the station that move from it
					C->InsertMovMB(*Bus);   //insert in the moving list
				}
				break;
			}


		}
	    break;
			if (MFBus.dequeue(Bus))   //if the capacity full dequeue
			{
				Bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());   //set time that the bus leave the station
				NumOfMBuses--;
				Bus->setSTN(SN);   //set the station that move from it
				C->InsertMovMB(*Bus);   //insert in the moving list
			}
		
		
	
	}
	//For forward Wheel Passangers
	WBus* Wbuss = nullptr;
	int PNP = NuPass;       //Number of passengers per min

	while (WFBus.peek(Wbuss))  //if the bus found
	{
		while (PNP > 0) //While get off/on in the same min 
		{
			
			 if (Wbuss->DeletePass(*Pass,SN))   //if there is a pass arrive to his final destnation
			{
				 Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
				C->InsertFPass(*Pass);          //insert inside finish list in the company
				PNP--;

			}
			else
			{
				
				if (WFBus.dequeue(Wbuss))        //if the capacity full dequeue
				{
					Wbuss->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());   //set time that the bus leave the station
					NumOfWBuses--;
					Wbuss->setSTN(SN);    //set the station that move from it
					C->InsertMovWB(*Wbuss);   //insert in the moving list
				}
				
				break;

			}


		}
		break;
			if (WFBus.dequeue(Wbuss))
			{
				Wbuss->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());   //set time that the bus leave the station
				NumOfWBuses--;
				Wbuss->setSTN(SN);     //set the station that move from it
				C->InsertMovWB(*Wbuss);   //insert in the moving list
			}
		

	}
	//For backward Mixed Passangers
	MBus* bus = nullptr;
	int PN = NuPass;       //Number of passengers per min

	while (MBBus.peek(bus))   //if the bus found
	{
		while (PN > 0)   //While get off/on in the same min 
		{
			
		    if (bus->DeletePass(*Pass,SN))   //if there is a pass arrive to his final destnation
			{
				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
				C->InsertFPass(*Pass);     //insert inside finish list in the company
				PN--;

			}
			else
			{
				
				if (MBBus.dequeue(bus))
				{
                 NumOfMBuses--;
				 bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());   //set time that the bus leave the station
				 bus->setSTN(SN);     //set the station that move from it
				 C->InsertBMovMB(*bus);   //insert in the moving list
				}
				break;


			}


		}
		break;
	    if (MBBus.dequeue(bus))
		{
		   NumOfMBuses--;
			bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
			bus->setSTN(SN);      //set the station that move from it
			C->InsertBMovMB(*bus);   //insert in the moving list
		}
	}
	//For Backward Wheel Passangers
	WBus* wBus = nullptr;
	int PNPMm = NuPass;       //Number of passengers per min

	while (WBBus.peek(wBus))       //if the bus found
	{
	
		while (PNPM > 0)      //While get off/on in the same min 
		{
			if (wBus->DeletePass(*Pass,SN))   //if there is a pass arrive to his final destnation
			{

				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
				C->InsertFPass(*Pass);
				PNPMm--;
			}
			else
			{
				
				if (WBBus.dequeue(wBus))   //if the capacity full dequeue
				{
					NumOfWBuses--;
					wBus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
					wBus->setSTN(SN);      //set the station that move from it
					C->InsertBMovWB(*wBus);   //insert in the moving list
				}
				break;

			}


		}
		break;
			if (WBBus.dequeue(wBus))   //if the capacity full dequeue
			{
				NumOfWBuses--;
				wBus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
				wBus->setSTN(SN);          //set the station that move from it
				C->InsertBMovWB(*wBus);   //insert in the moving list
			}
		
	}

}


bool Stations::search(int id)
{
	if (FNP.search_by_ID(id))
		return true;
	else if (BNP.search_by_ID(id))
		return true;
	else
	return false;
}

void Stations::BusBordring(int getTime, Company* C,int SN)
{
	const int NuPass= floor(60 / getTime);
	//For forward Mixed Passangers
	MBus* Bus = nullptr;
	Passenger* Pass = new Passenger();
	int PNPM = NuPass;       //Number of passengers per min
	while (MFBus.peek(Bus))    //if the bus found 
	{
        while (PNPM > 0)    //While get off/on in the same min 
		{
		    if (FSP.dequeue(Pass))     //if there is pass
			{
				Pass->SetMT(C->getTime()->get_hh(), C->getTime()->get_mm());
				if (Bus->InsertPass(*Pass))    //insert in the bus
				{
					NumWPS--;
					PNPM--;
				}
				else
				{
					
					if (MFBus.dequeue(Bus))   //if the capacity full dequeue
					{
						NumOfMBuses--;
						Bus->SetTime(C->getTime()->get_hh(),C->getTime()->get_mm());    //set time that the bus leave the station
						Bus->setSTN(SN);      //set the station that move from it
						C->InsertMovMB(*Bus);   //insert in the moving list
					}
					
					break;
				}
			}
         	else if (FNP.dequeue(Pass))   //if there is pass
			{
				Pass->SetMT(C->getTime()->get_hh(), C->getTime()->get_mm());
			if (Bus->InsertPass(*Pass))   //insert in the bus
				{
					NumWPN--;
					PNPM--;
				}
				else
				{
					
					if (MFBus.dequeue(Bus))    //if the capacity full dequeue
					{
						Bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
						NumOfMBuses--;
						Bus->setSTN(SN);      //set the station that move from it
						C->InsertMovMB(*Bus);   //insert in the moving list
					}
					break;
				}
			}
  			else if (Bus->DeletePass(*Pass,SN))    //if there is a pass arrive to his final destnation
			{
				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
             C->InsertFPass(*Pass);       //insert inside finish list in the company
				PNPM--;

			}
			else
			{

				
				if (MFBus.dequeue(Bus))   //if the capacity full dequeue
				{
					Bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());   //set time that the bus leave the station
					NumOfMBuses--;
					Bus->setSTN(SN);      //set the station that move from it
					C->InsertMovMB(*Bus);   //insert in the moving list
				}
				break;
			}


		}
	    break;
			if (MFBus.dequeue(Bus))
			{
				Bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
				NumOfMBuses--;
				Bus->setSTN(SN);    //set the station that move from it
				C->InsertMovMB(*Bus);   //insert in the moving list
			}
		
		
	
	}
	//For forward Wheel Passangers
	WBus* Wbuss = nullptr;
	int PNP = NuPass;       //Number of passengers per min

	while (WFBus.peek(Wbuss))      //if the bus found
	{
		while (PNP > 0)    //While get off/on in the same min 
		{
			if (FWH.dequeue(Pass))   //if there is pass
			{
				Pass->SetMT(C->getTime()->get_hh(), C->getTime()->get_mm());
				if (Wbuss->InsertPass(*Pass))    //insert in the bus
				{

					NumWPW--;
					PNP--;
				}
				else
				{
					
					if (WFBus.dequeue(Wbuss))   //if the capacity full dequeue
					{
						Wbuss->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
						NumOfWBuses--;
						Wbuss->setSTN(SN);        //set the station that move from it
						C->InsertMovWB(*Wbuss);   //insert in the moving list
					}
					
					break;


				}
			}
			else if (Wbuss->DeletePass(*Pass,SN))  //if there is a pass arrive to his final destnation
			{
				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
				C->InsertFPass(*Pass);      //insert inside finish list in the company
				PNP--;

			}
			else
			{
				
				if (WFBus.dequeue(Wbuss))    //if the capacity full dequeue
				{
					Wbuss->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
					NumOfWBuses--;
					Wbuss->setSTN(SN);           //set the station that move from it
					C->InsertMovWB(*Wbuss);   //insert in the moving list
				}
				
				break;

			}


		}
		break;
			if (WFBus.dequeue(Wbuss))   //if the capacity full dequeue
			{
				Wbuss->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
				NumOfWBuses--;
				Wbuss->setSTN(SN);          //set the station that move from it
				C->InsertMovWB(*Wbuss);   //insert in the moving list
			}
		

	}
	//For backward Mixed Passangers
	MBus* bus = nullptr;
	int PN = NuPass;       //Number of passengers per min

	while (MBBus.peek(bus))   //if the bus found
	{
		while (PN > 0)       //While get off/on in the same min 
		{
			if (BSP.dequeue(Pass))     //if there is pass
			{
				Pass->SetMT(C->getTime()->get_hh(), C->getTime()->get_mm());
				if (bus->InsertPassB(*Pass))   //insert in the bus
				{
					NumWPS--;
					PN--;
				}
				else
				{
					if (MBBus.dequeue(bus))    //if the capacity full dequeue
					{
						bus->SetTime(C->getTime()->get_hh(),C->getTime()->get_mm());    //set time that the bus leave the station
						NumOfMBuses--;
						bus->setSTN(SN);       //set the station that move from it
						C->InsertBMovMB(*bus);   //insert in the moving list
					}
					
					break;


				}
			}
			else if (BNP.dequeue(Pass))   //if there is pass
			{
				Pass->SetMT(C->getTime()->get_hh(), C->getTime()->get_mm());
				if (bus->InsertPassB(*Pass))   //insert in the bus
				{
					NumWPN--;
					PN--;
				}
				else
				{
					
					if (MBBus.dequeue(bus))    //if the capacity full dequeue
					{
						bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());     //set time that the bus leave the station
                        NumOfMBuses--;
						bus->setSTN(SN);      //set the station that move from it
						C->InsertBMovMB(*bus);   //insert in the moving list
					}
					break;


				}
			}
			else if (bus->DeletePass(*Pass,SN))   //if there is a pass arrive to his final destnation
			{
				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
				C->InsertFPass(*Pass);        //insert inside finish list in the company
				PN--;

			}
			else
			{
				
				if (MBBus.dequeue(bus))   //if the capacity full dequeue
				{
                 NumOfMBuses--;
				 bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
				 bus->setSTN(SN);           //set the station that move from it
				 C->InsertBMovMB(*bus);   //insert in the moving list
				}
				break;


			}


		}
		break;
	    if (MBBus.dequeue(bus))
		{
		   NumOfMBuses--;
			bus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());     //set time that the bus leave the station
			bus->setSTN(SN);          //set the station that move from it
			C->InsertBMovMB(*bus);   //insert in the moving list
		}
	}
	//For Backward Wheel Passangers
	WBus* wBus = nullptr;
	int PNPMm = NuPass;       //Number of passengers per min
	 
	while (WBBus.peek(wBus))    //if the bus found
	{
	
		while (PNPM > 0)    //While get off/on in the same min 
		{
			if (BWH.dequeue(Pass))      //if there is pass
			{
				Pass->SetMT(C->getTime()->get_hh(), C->getTime()->get_mm());
				if (wBus->InsertPassB(*Pass))      //insert in the bus
				{
					NumWPW--;

					PNPMm--;
				}
				else
				{
					
					if (WBBus.dequeue(wBus))   //if the capacity full dequeue
					{
                      NumOfWBuses--;
					wBus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());     //set time that the bus leave the station
					wBus->setSTN(SN);          //set the station that move from it
					C->InsertBMovWB(*wBus);   //insert in the moving list
					}
					break;



				}
			}
			else if (wBus->DeletePass(*Pass,SN))     //if there is a pass arrive to his final destnation
			{
				Pass->SetFT(C->getTime()->get_hh(), C->getTime()->get_mm());
				C->InsertFPass(*Pass);          //insert inside finish list in the company
				PNPMm--;
			}
			else
			{
				
				if (WBBus.dequeue(wBus))   //if the capacity full dequeue
				{
					NumOfWBuses--;
					wBus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());   //set time that the bus leave the station
					wBus->setSTN(SN);          //set the station that move from it
					C->InsertBMovWB(*wBus);   //insert in the moving list
				}
				break;

			}


		}
		break;
			if (WBBus.dequeue(wBus))   //if the capacity full dequeue
			{
				NumOfWBuses--;
				wBus->SetTime(C->getTime()->get_hh(), C->getTime()->get_mm());    //set time that the bus leave the station
				wBus->setSTN(SN);           //set the station that move from it
				C->InsertBMovWB(*wBus);   //insert in the moving list
			}
		
	}

}

