#include "MotorMasinuta.h"
#include<iostream>
#include<string>
using namespace std;

CarEngine::CarEngine(string nume, string culoare, int lungime, int latime, int caiPutere, int ID)
	:Component(nume,culoare,lungime,latime,ID),caiPutere(caiPutere)
{

}

string CarEngine::print()
{
	string comp = "MotorMasinuta: ";
	comp += Component::print();
	comp += " " + to_string(caiPutere);
	return comp;
}

void CarEngine::printForDisplay()
{
	cout << nume << " " << culoare << " <" << lungime << ", " << latime << "> " << caiPutere << endl;
}

void CarEngine::read(istream& in)
{
	string text;
	string cuvant;

	in >> ID;
	in.ignore();
	in >> nume;
	in >> culoare;

	getline(in, text);
	text = text.substr(2, text.length());
	string delimiter = "<>,";
	size_t pos = 0;
	pos = text.find_first_of(delimiter);
	cuvant = text.substr(0, pos);
	text.erase(0, pos + 1);
	lungime = stoi(cuvant);
	pos = text.find_first_of(delimiter);
	cuvant = text.substr(0, pos);
	text.erase(0, pos + 1);
	latime = stoi(cuvant);
	caiPutere = stoi(cuvant);
}
