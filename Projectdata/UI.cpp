#include "UI.h"
#include <iostream>
using namespace std;




UI::UI()
{
	t = 0;
	time = new Time();
	time->Set_hh(4);
	time->set_mm(0);
}

void UI::Type()
{
	cout << "Choose type:" << endl;
	cout << "1) Interactive mode" << endl;
	cout << "2) Silent mode" << endl;
	int x;
	cin >> x;
	t = x;
}
int UI::getType()
{
	return t;
}
void UI::Print(Company* C, Time* time)
{
	if (t == 1)
	{ 

		system("cls");
		for (int i = 0; i < C->Get_S(); i++)
		{
			Stations station= C->GetStation()[i];
			cout << "Current Time(Hour:Min)==> " << time->get_hh() << ":" << time->get_mm() << endl;

			cout << "===================     Station #" << i << "     ==================" << endl;
			cout << station.Get_NumWPs() << "  Waiting SP:"  << "  FWD[";
			station.PrintFSP();
			cout << "] BCK[";
			station.PrintBSP();
			cout<< "]" << endl;
			cout << station.Get_NumWPw() << "  Waiting WP:  FWD[";
			station.PrintFWP();
			cout << "] BCK[";
			station.PrintBWP();
			cout<< "]" << endl;
			cout << station.Get_NumWPn() << "  Waiting NP:  FWD[";
			station.PrintFNP();
			cout << "] BCK[";
			station.PrintBNP();
			cout<< "]" << endl;
			
			cout << station.Get_NumofMbuses() + station.Get_NumOfWbuses() << " busses at this station:"<<endl;
			cout << "----------------------------------------------------------" << endl;
			station.PrintBusinfo();
			cout << C->Get_NumFP() << " Finished Passenger :";
			C->PrintFIDP();
			cout <<endl<< "Press any key to display next station" << endl;
			system("pause>nul");
 			system("cls");
		}
		
	}
}

void UI::PrintS(Company* C)
{
	if (t == 2)
	{
		system("cls");
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts" << endl;
		if (C->IsSimuOver())
		{
			cout << "Simulation ends, Output file created" << endl;
			system("pause>nul");
		}
	}

}



void UI::PrintSto(Company* C, Time* time)
{
	system("cls");
	
		Stations station = C->GetStation()[0];
		cout << "Current Time(Hour:Min)==> " << time->get_hh() << ":" << time->get_mm() << endl;

		cout << "===================     Station #0    ==================" << endl;
		cout << station.Get_NumWPs() << "  Waiting SP:" << "  FWD[";
		station.PrintFSP();
		cout << "] BCK[";
		station.PrintBSP();
		cout << "]" << endl;
		cout << station.Get_NumWPw() << "  Waiting WP:  FWD[";
		station.PrintFWP();
		cout << "] BCK[";
		station.PrintBWP();
		cout << "]" << endl;
		cout << station.Get_NumWPn() << "  Waiting NP:  FWD[";
		station.PrintFNP();
		cout << "] BCK[";
		station.PrintBNP();
		cout << "]" << endl;

		cout << station.Get_NumofMbuses() + station.Get_NumOfWbuses() << " busses at this station:" << endl;
		cout << "----------------------------------------------------------" << endl;
		station.PrintBusinfo();
		cout << C->Get_NumFP() << " Finished Passenger :";
		C->PrintFIDP();
		cout << endl << "Press any key to display next station" << endl;
		system("pause>nul");

	
}
UI::~UI()
{   
}


