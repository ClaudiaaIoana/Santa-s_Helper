#include "Viewer.h"
#include"Controler.h"
#include<iostream>
#include<conio.h>
#include <chrono>
#include <thread>

using namespace std;

Viewer* Viewer::instance = nullptr;

Viewer* Viewer::getInstance()
{
	if (!instance)
		instance = new Viewer();
	return instance;
}

void Viewer::destroyInstance()
{
	if (instance)
		delete instance;
}

void Viewer::startingScreen()
{
	clear();
	cout << "\t\t\t\tLogin" << endl << "\t\t\t\tRegister" << endl << "\t\t\t\t<exit>" << endl;

}

void Viewer::clear()
{
	system("cls");
}

void Viewer::conectedScreen()
{
	clear();
	cout << "\t\t\t\t\tConected";
	this_thread::sleep_for(1000ms);
}

void Viewer::wrongUserName()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tINCORRECT USERNAME" << endl;
	cout << endl << "\t\t\t\t\tRetry" << endl;
	cout << endl << "\t\t\t\t\tGo Back";
}

void Viewer::chooseAccount()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tSANTA" << endl<<endl << "\t\t\t\tELF";
	
}

void Viewer::allreadyRegistered()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tALLREADY REGISTERED";
	this_thread::sleep_for(1500ms);
}

void Viewer::wrongPassword()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tWRONG PASSWORD";
	this_thread::sleep_for(1500ms);
}

void Viewer::tooManyTries()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tTOO MANY TRIES";
	this_thread::sleep_for(1500ms);
}

void Viewer::santaOptions()
{
	clear();
	cout << endl << endl ;
	cout << "\t\t\t\tEdit children list"<<endl<<endl;
	cout << endl << "\t\t\t\tADD CHILD";
	cout << endl << "\t\t\t\tDELETE CHILD";
	cout << endl << "\t\t\t\tMODIFY SOMEONE'S DATA";
	cout << endl << "\t\t\t\tLOGOUT"<<endl<<endl;
	printChildren();
}

void Viewer::printChildren()
{
	BD* bd = BD::getInstance();
	for (auto it = bd->getCopii().begin(); it != bd->getCopii().end(); it++)
	{
		(*it)->printForDisplay();
	}
}

Copil* Viewer::addChildScreen()
{
	clear();
	printChildren();
	cout << endl << "\t\t ADD:\t";
	string nume;
	string prenume;
	string status;
	bool cuminte;
	string dataNastere;
	string adresaCurenta;
	cout << endl << "\t\t\tLast Name: ";
	cin >> nume;
	cout << endl << "\t\t\tFirst Name: ";
	cin >> prenume;
	cout << endl << "\t\t\tStatus<good/bad>: ";
	cin >> status;
	if (status == "good")
		cuminte = true;
	else cuminte = false;
	cout << endl << "\t\t\tDate of Birth: ";
	cin >> dataNastere;
	cin.ignore();
	cout << endl << "\t\t\tCurrent Adress: ";
	getline(cin, adresaCurenta);
	Copil* copil = new Copil(nume, prenume, dataNastere, adresaCurenta, cuminte);
	return copil;
}

string Viewer::deleteChildScreen()
{
	clear();
	printChildren();
	cout << endl << "\t\t DELETE:\t";
	string nume;
	cout << endl << "\t\t\tFull Name: ";
	getline(cin, nume);
	return nume;
}

string Viewer::chooseChild()
{
	clear();
	cout << "\t\t\t\tMODIFY CHILD'S DATA"<<endl;
	printChildren();
	cout << endl << endl;
	cout << "\t\t\t\tEnter the full NAME:";
	string name;
	getline(cin, name);
	return name;
}

void Viewer::modifyChildData(const Copil* copil)
{
	clear();
	copil->printForDisplay();
	cout << endl << "\t\t\t\tGIVE A GIFT";
	cout << endl << "\t\t\t\tADD WISH";
	cout << endl << "\t\t\t\tCHANCE CURRENT ADRESS";
	cout << endl << "\t\t\t\tCHANGE STATUS";
	cout << endl << "\t\t\t\tGO BACK";
}

void Viewer::unfoundGift()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tCOULDN'T FINT THE GIFT";
	this_thread::sleep_for(1500ms);
}

void Viewer::elfOptions()
{
	clear();
	cout << endl << endl<<endl<<endl;
	cout << "\t\t\t\tVIEW GIFT DEPO";
	cout << endl << "\t\t\t\tVIEW COMPONENT DEPO";
	cout << endl << "\t\t\t\tLOGOUT" << endl << endl;
}

void Viewer::printGifts()
{
	BD* bd = BD::getInstance();
	for (auto it = bd->getCadouri().begin(); it != bd->getCadouri().end(); it++)
	{
		(*it)->printForDisplay();
	}
}

void Viewer::elfGiftOptions()
{
	clear();
	cout << endl << "\t\t\t\tMAKE A NEW GIFT";
	cout << endl << "\t\t\t\tMODIFY GIFT";
	cout << endl << "\t\t\t\tBACK";
	cout << endl << endl;
	printGifts();
}

Cadou* Viewer::addGift()
{
	string name;
	string package;
	Cadou::Package pck = Cadou::Package::box;
	clear();
	printGifts();
	cout << "\t\t\t\tName: ";
	cin >> name;
	cout << endl << "\t\t\t\tPackage <box/paper>: ";
	cin >> package;
	cin.ignore();
	if (package == "box")
		pck = Cadou::Package::box;
	else if (package == "paper")
		pck = Cadou::Package::paper;
	Cadou* cadou = new Cadou(name, pck);
	return cadou;
}

string Viewer::chooseGift()
{
	clear();
	printGifts();
	cout << endl << endl;
	cout << "\t\t\t\tEnter gift's name: ";
	string name;
	cin.ignore() >> name;
	return name;
}

void Viewer::modifyGift(Cadou* cadou)
{
	clear();
	cadou->printForDisplay();
	cout << endl << endl;
	cout << "\t\t\t\tADD COMPONENT";
	cout << endl << "\t\t\t\tCHANGE PACKAGE";
	cout << endl << "\t\t\t\tBACK";
}

void Viewer::addComponentToGift(Cadou* cadou)
{
	clear();
	cadou->printForDisplay();
	cout << endl << endl << "Introduce component (name): ";
}

void Viewer::unfoundComponent()
{
	clear();
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\tCOULDN'T FIND COMPONENT";
	this_thread::sleep_for(1500ms);
}

void Viewer::elfComponentOptions()
{
	clear();
	cout << endl << "\t\t\t\tADD STANDARD COMPONENT";
	cout << endl << "\t\t\t\tADD CAR ENGINE";
	cout << endl << "\t\t\t\tBACK";
	cout << endl << endl;
	printComponent();
}

void Viewer::printComponent()
{
	BD* bd = BD::getInstance();
	for (auto it = bd->getComponente().begin(); it != bd->getComponente().end(); it++)
	{
		(*it)->printForDisplay();
	}
}

Component* Viewer::addMotor()
{
	string name;
	string colour;
	int lungime;
	int latime;
	int caiPutere;
	clear();
	printComponent();
	cout << "\t\t\t\tName: ";
	cin >> name;
	cout <<"\t\t\t\tColour: ";
	cin >> colour;
	cout << "\t\t\t\tLenght: ";
	cin >> lungime;
	cout<< "\t\t\t\tWidth: ";
	cin >> latime;
	cout<< "\t\t\t\tPower: ";
	cin >> caiPutere;
	CarEngine* motor = new CarEngine(name, colour, lungime, latime, caiPutere);
	return motor;
}

Component* Viewer::addStandardComponent()
{
	string name;
	string colour;
	int lungime;
	int latime;
	int caiPutere;
	clear();
	printComponent();
	cout << "\t\t\t\tName: ";
	cin >> name;
	cout << "\t\t\t\tColour: ";
	cin >> colour;
	cout <<"\t\t\t\tLenght: ";
	cin >> lungime;
	cout << "\t\t\t\tWidth: ";
	cin >> latime;
	StdComponent* comp = new StdComponent(name, colour, lungime, latime);
	return comp;
}


