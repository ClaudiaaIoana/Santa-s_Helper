#define _CRT_SECURE_NO_WARNINGS
#include "Cadou.h"
#include"BD.h"
#include<iostream>
#include<random>
using namespace std;

vector<int> Cadou::IDS;

Cadou::Cadou(string nume, Package package, int ID)
	:nume(nume), package(package)
{
	if (ID == 0)
		createID();
	else this->ID = ID;
}

Cadou::Cadou(const Cadou& cadou)
{
	createID();
	this->nume = cadou.nume + "NEW";
	this->package = cadou.package;
	this->componente = cadou.componente;
}

void Cadou::createID()
{
	srand(time(NULL));
	ID = 10000 + rand() % 89999;
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

int Cadou::getID()
{
	return ID;
}

string Cadou::getNume()
{
	return nume;
}

void Cadou::printForDisplay()
{
	cout << nume << " ";
	if (package == Package::box)
		cout << "<box> ";
	else if (package == Package::paper)
		cout << "<paper> ";
	cout << endl << "Components: ";
	string compName;
	for (auto it = componente.begin(); it != componente.end(); it++)
	{
		Component* componenta = BD::getInstance()->searchComponenta(*it);
		if (componenta)
		{
			compName = componenta->getNume();
			cout << compName << " ";
		}
	}
	cout << endl << endl;
}

void Cadou::changePackage()
{
	if (package == box)
		package = paper;
	else package = box;
}

void Cadou::addComponent(int componentID)
{
	componente.push_back(componentID);
}

ostream& operator<<(ostream& out, Cadou* cadou)
{
	out << cadou->ID << " " << cadou->nume << " ";
	if (cadou->package == Cadou::box)
		out << "<box>: ";
	else out << "<paper>: ";
	for (auto it = cadou->componente.begin(); it != cadou->componente.end(); it++)
	{
		out << (*it) << " ";
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Cadou* cadou)
{
	in >> cadou->ID;
	in >> cadou->nume;
	string package;
	in >> package;
	if (package=="<paper>:")
		cadou->package = Cadou::paper;
	else cadou->package = Cadou::box;

	string components;
	string delimiter = " ";
	size_t pos = 0;
	string componenta;
	getline(in, components);
	components= components.substr(1, components.length());
	while ((pos = components.find(delimiter)) != string::npos) {
		componenta = components.substr(0, pos);
		components.erase(0, pos+1);
		int id = stoi(componenta);
		cadou->componente.push_back(id);
	}
	if(components!="")
		cadou->componente.push_back(stoi(components));
	
	return in;
	
}
