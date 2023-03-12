#include "Copil.h"
#include<iostream>

Copil::Copil(string nume, string prenume, string dataNasterii, string adresaCurenta,bool good,int ID)
	:Persoana(nume,prenume,dataNasterii,adresaCurenta,ID),good(good)
{
}

Copil::~Copil()
{
}

void Copil::addCadouDorit(int idCadou)
{
	this->cadouriDorite.push_back(idCadou);
}

void Copil::addCadouPrimit(int idCadou)
{
	this->cadouriPrimite.push_back(idCadou);
}

void Copil::printForDisplay() const
{
	cout << this->nume << " " << prenume;
	if (good)
		cout << " <good> ";
	else cout << " <bad> ";
	cout << dataNasterii << " ";
	cout << adresaCurenta << endl;
}

void Copil::changeStatus()
{
	good = !good;
}

ostream& operator<<(ostream& out, Copil* copil)
{
	out << copil->ID << " " << copil->nume << " " << copil->prenume;
	if (copil->good)
		out << " <good> ";
	else out << " <bad> ";
	out << copil->dataNasterii;
	out <<endl<< "< " << copil->adresaCurenta;
	for (auto it = copil->adrese.begin(); it != copil->adrese.end(); it++)
		out << "; " << (*it);
	out << " >"<<endl<<"Wishes:";
	for (auto it = copil->cadouriDorite.begin(); it != copil->cadouriDorite.end(); it++)
		out << " " << (*it);
	out << endl << "Received:";
	for (auto it = copil->cadouriPrimite.begin(); it != copil->cadouriPrimite.end(); it++)
		out << " " << (*it);
	out << endl ;
	return out;
}

istream& operator>>(istream& in, Copil* copil)
{
	in >> copil->ID;
	in >> copil->nume;
	in >> copil->prenume;
	string text;
	in >> text;
	if (text == "<good>")
		copil->good = true;
	else copil->good = false;
	in >> copil->dataNasterii;
	in.ignore();
	
	getline(in, text);
	string delimiter = "<>;";
	size_t pos = 0;
	string adress;
	pos = text.find_first_of(delimiter);
	text.erase(0, pos + 2);
	pos = text.find_first_of(delimiter);
	adress = text.substr(0, pos);
	text.erase(0, pos + 2);
	copil->adresaCurenta = adress;
	while ((pos = text.find_first_of(delimiter)) != string::npos) {
		adress = text.substr(0, pos);
		text.erase(0, pos + 2);
		copil->addAdresa(adress);
	}

	string cadou;
	in >> cadou;
	getline(in, text);
	if (text != "")
	{
		text = text.substr(1, text.length());
		delimiter = " ";
		pos = 0;
		while ((pos = text.find(delimiter)) != string::npos) {
			cadou = text.substr(0, pos);
			text.erase(0, pos + delimiter.length());
			copil->addCadouDorit(stoi(cadou));
		}
		if (text != "")
			copil->addCadouDorit(stoi(text));
	}

	in >> cadou;
	getline(in, text);
	if (text != "")
	{
		text = text.substr(1, text.length());
		pos = 0;
		while ((pos = text.find(delimiter)) != string::npos) {
			cadou = text.substr(0, pos);
			text.erase(0, pos + delimiter.length());
			copil->addCadouPrimit(stoi(cadou));
		}
		if (text != "")
			copil->addCadouDorit(stoi(text));
	}

	return in;
}
