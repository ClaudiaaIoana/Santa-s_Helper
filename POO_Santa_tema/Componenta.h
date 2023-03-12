#pragma once
#include<string>
#include<vector>
using namespace std;
class CarEngine;
class StdComponent;
class Component
{
	static vector<int>IDS;
protected:
	int ID;
	string nume;
	string culoare;
	int lungime;
	int latime;
public:
	Component()=default;
	Component(string nume, string culoare, int lungime, int latime, int ID = 0);
	virtual ~Component();
	void createID();
	int getID();
	string getNume();
	virtual string print();
	virtual void printForDisplay()=0;
	friend ostream& operator<<(ostream& out, Component* componeneta);
	virtual void read(istream& in)=0;
	friend istream& operator>>(istream& in, Component* componenta);
};

class ComponentFactory
{
public:
	static Component* makeMotor();
	static Component* makeStandardComponent();
};
