#include "Passenger.h"

Passenger::Passenger()
{
    ATH = 0;
    ATM = 0;
    Strt_Station = nullptr;
    End_Station = nullptr;
    GetOnOffTime = 0;
    PassType = " ";
    NUMofPRI = 0;
    END = 0;
    SPT = " ";
     TT=new Time();
     WT=new Time();
     MT=new Time();
     FT=new Time();

}

Passenger::Passenger(int ath, int atm,int id, Stations* StrtStation, Stations* EndStation, int getOnOffTime, string Pass_Type, string pt,int end)
{
    ATH = ath;
    ATM = atm;
    Strt_Station = StrtStation;
    End_Station = EndStation;
    GetOnOffTime = getOnOffTime;
    PassType = Pass_Type;
    SPT = pt;
    ID = id;
    END = end;
    if (SPT == "Preg")
        NUMofPRI = 2;
    else if(SPT=="aged")
        NUMofPRI = 1;
    else if(SPT=="POD")
        NUMofPRI = 3;
    TT = new Time();
    WT = new Time();
    MT = new Time();
    FT = new Time();
}

Passenger::Passenger(int ath, int atm,int id, Stations* StrtStation, Stations* EndStation, int getOnOffTime, string Pass_Type,int end)
{
    ATH = ath;
    ATM = atm;
    Strt_Station = StrtStation;
    End_Station = EndStation;
    GetOnOffTime = getOnOffTime;
    NUMofPRI = 0;
    PassType = Pass_Type;
    ID = id;
    SPT = " ";
    END = end;
    TT = new Time();
    WT = new Time();
    MT = new Time();
    FT = new Time();

}

    


Passenger::~Passenger()
{
}

Stations* Passenger::Get_Strt_Station()
{
    return Strt_Station;
}

Stations* Passenger::Get_End_Station()
{
    return End_Station;
}

int Passenger::Get_GetOnOffTime()
{
    return GetOnOffTime;
}

int Passenger::GetNUMofPRI()
{
    return NUMofPRI;
}

int Passenger::GetEndStat()
{
    return END;
}

int Passenger::Get_ID()
{
    return ID;
}

void Passenger::Set_ID(int id)
{
    ID = id;
}

int Passenger::Get_ATH()
{
    return ATH;
}

int Passenger::Get_ATM()
{
    return ATM;
}

void Passenger::CalTT()
{
    Time* T = new Time();
    T->CalulateTimeDifference(*FT , *MT);
    TT = T;
}

void Passenger::CalWT()
{
    Time* T = new Time();
    Time* AT = new Time(ATH, ATM);
    T->CalulateTimeDifference(*MT, *AT);
    WT = T;
}

void Passenger::SetFT(int h, int m)
{
    FT->Set_hh(h);
    FT->set_mm(m);
}
void Passenger::SetMT(int h, int m)
{
    MT->Set_hh(h);
    MT->set_mm(m);
}
int Passenger::GetTTh()
{
    CalTT();
    return TT->get_hh();
}
int Passenger::GetWTh()
{
    CalWT();
    return WT->get_hh();
}
int Passenger::GetFTh()
{
    return FT->get_hh();
}
int Passenger::GetMTh()
{
    return MT->get_hh();
}
int Passenger::GetTTm()
{
    CalTT();
    return TT->get_mm();
}
int Passenger::GetWTm()
{
    CalWT();
    return WT->get_mm();
}
int Passenger::GetFTm()
{
    return FT->get_mm();
}
int Passenger::GetMTm()
{
    return MT->get_mm();
}
void Passenger::Set_Strt_Station(Stations* Strt)
{
    Strt_Station = Strt;
}

void Passenger::Set_End_Station(Stations* End)
{
    End_Station = End;
}

void Passenger::Set_GetOnOffTime(int OnOffTime)
{
    GetOnOffTime = OnOffTime;
}

void Passenger::Set_PassengerType(string Type)
{
    PassType = Type;
}

void Passenger::Set_Pass_SP(string SP)
{
    SPT = SP;
}

void Passenger::Set_ATH(int Ath)
{
    ATH = Ath;
}

void Passenger::Set_ATM(int Atm)
{
    ATM = Atm;

}
string Passenger::Get_PassengerType()
{
    return PassType;
}

string Passenger::Get_Pass_SP()
{
    return SPT;
}

