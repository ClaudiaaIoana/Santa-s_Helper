#pragma once
#include"Persoana.h"
#include"Cadou.h"
class Copil:public Persoana
{
	vector<int> cadouriDorite;
	vector<int> cadouriPrimite;
	bool good;
public:
	Copil() = default;
	Copil(string nume, string prenume, string dataNasterii, string adresaCurenta,bool good,int ID=0);
	~Copil();
	void addCadouDorit(int idCadou);
	void addCadouPrimit(int idCadou);
	void printForDisplay()const;
	void changeStatus();
	friend ostream& operator<<(ostream& out, Copil* copil);
	friend istream& operator>>(istream& in, Copil* copil);
};

