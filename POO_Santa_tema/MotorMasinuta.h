#pragma once
#include"Componenta.h"
class CarEngine:public Component
{
	int caiPutere;
public:
	CarEngine() = default;
	CarEngine(string nume, string culoare, int lungime, int latime, int caiPutere, int ID = 0);
	string print() override;
	void printForDisplay()override;
	void read(istream& in) override;
};

