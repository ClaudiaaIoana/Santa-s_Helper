#include "Persoana.h"
#include<random>

vector<int> Persoana::IDS;

Persoana::Persoana(string nume, string prenume, string dataNasterii,string adresaCurenta,int ID)
	:nume(nume),prenume(prenume),dataNasterii(dataNasterii),adresaCurenta(adresaCurenta)
{
	if (ID == 0)
		createID();
	else this->ID=ID;
}

Persoana::~Persoana()
{
}

void Persoana::addAdresa(string adresa)
{
	adrese.push_back(adresa);
}

int Persoana::getID()
{
	return ID;
}

void Persoana::changeCurrentAdress(string newAdress)
{
	adrese.push_back(adresaCurenta);
	this->adresaCurenta = newAdress;
}

string Persoana::getNume()
{
	return nume+" "+prenume;
}

void Persoana::createID()
{
	srand(time(NULL));
	ID = 1000 + rand() % 8999;
	int ok = 1;
	while (ok)
	{ 
		ok = 0;
		for (auto it = IDS.begin(); it != IDS.end(); it++)
		{
			if (*it = ID)
			{
				ok = 1;
				ID = 1000 + rand() % 999;
			}
		}
	}
}
