// Projectdata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include"Company.h"

int main()
{
    Company* obj=new Company;
    obj->Simulate("test6.txt");    //calling function simulate from company
}

