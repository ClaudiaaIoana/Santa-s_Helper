#pragma once
#include<string>
using namespace std;
__interface IPersoana
{
	virtual void addAdresa(string adresa)=0;
	virtual int getID()=0;
	virtual string getNume()=0;
	virtual void changeCurrentAdress(string newAdress)=0;
	virtual void createID()=0;
};

