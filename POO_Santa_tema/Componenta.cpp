#include "Componenta.h"
#include"MotorMasinuta.h"
#include"StdComponent.h"
#include<iostream>
#include<random>
using namespace std;

vector<int> Component::IDS;

Component::Component(string nume, string culoare, int lungime, int latime, int ID)
	:nume(nume),culoare(culoare),lungime(lungime),latime(latime)
{
	if (ID == 0)
	{
		createID();
	}
	else this->ID = ID;
}

Component::~Component()
{
}

void Component::createID()
{
	srand(time(NULL));
	ID = 100000 + rand() % 899999;
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

int Component::getID()
{
	return ID;
}

string Component::getNume()
{
	return nume;
}

string Component::print()
{
	string comp;
	comp = to_string(ID);
	comp += ": " + nume + " " + culoare + " <" + to_string(lungime) + "," + to_string(latime) + ">";
	return comp;
}

ostream& operator<<(ostream& out, Component* componeneta)
{
	out << componeneta->print()<<endl;
	return out;
}

istream& operator>>(istream& in, Component* componenta)
{
	componenta->read(in);
	return in;
}

Component* ComponentFactory::makeMotor()
{
	return new CarEngine();
}

Component* ComponentFactory::makeStandardComponent()
{
	return new StdComponent();
}
