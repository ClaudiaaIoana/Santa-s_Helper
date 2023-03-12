#pragma once
#include"Componenta.h"
#include<vector>
class Cadou
{
public:
	enum Package { box = 0, paper = 1 };
protected:
	static vector<int> IDS;
	int ID;
	string nume;
	vector<int> componente;
	Package package;
public:
	Cadou() = default;
	Cadou(string nume, Package package, int ID = 0);
	Cadou(const Cadou& cadou);
	int getID();
	string getNume();
	void printForDisplay();
	void changePackage();
	void addComponent(int componentID);
	friend ostream& operator<<(ostream& out, Cadou* cadou);
	friend istream& operator>>(istream& in, Cadou* cadou);
private:
	void createID();

};
