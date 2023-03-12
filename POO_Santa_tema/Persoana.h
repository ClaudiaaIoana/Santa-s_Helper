#pragma once
#include<string>
#include<vector>
using namespace std;
class Persoana
{
protected:
	static vector<int> IDS;
	int ID;
	string nume;
	string prenume;
	string dataNasterii;
	vector<string> adrese;
	string adresaCurenta;
public:
	Persoana() = default;
	Persoana(string nume, string prenume, string dataNasterii, string adresaCurenta, int ID = 0);
	virtual ~Persoana();
	void addAdresa(string adresa);
	int getID();
	string getNume();
	void changeCurrentAdress(string newAdress);
private:
	void createID();
};

