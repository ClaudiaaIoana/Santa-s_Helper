#include "StdComponent.h"

StdComponent::StdComponent(string nume, string culoare, int lungime, int latime, int ID)
	:Component(nume, culoare, lungime, latime,ID)
{
}

string StdComponent::print()
{
	string toPrint;
	toPrint = "StdComponent: ";
	toPrint += Component::print();
	return toPrint;
}

void StdComponent::printForDisplay()
{
	cout << nume << " " << culoare << " <" << lungime << ", " << latime << "> " << endl;
}

void StdComponent::read(istream& in)
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
}
