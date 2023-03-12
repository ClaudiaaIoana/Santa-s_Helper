#pragma once
#include"Componenta.h"
#include<iostream>
class StdComponent:public Component
{
public:
	StdComponent() = default;
	StdComponent(string nume, string culoare, int lungime, int latime, int ID = 0);
	string print() override;
	void printForDisplay() override;
	void read(istream& in)override;
};

