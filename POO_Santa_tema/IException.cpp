#include "IException.h"
#include"Viewer.h"
#include"Controler.h"
#include<iostream>
using namespace std;

int ExceptionPassword::tries = 0;

ExceptionFile::ExceptionFile(string mesaj, int cod)
	:mesaj(mesaj),cod(cod)
{
}

void ExceptionFile::print()
{
	cout << "working with file " << mesaj << " failed " << cod;
}

ExceptionPassword::ExceptionPassword()
{
	tries++;
}

bool ExceptionPassword::handle()
{
	if (tries == 3)
	{
		tries = 0;
		return false;
	}
	return true;
}

void ExceptionPassword::print()
{
	Viewer* view = Viewer::getInstance();
	view->wrongPassword();
	view->clear();
}

void ExceptionUsser::print()
{
	Viewer* view = Viewer::getInstance();
	view->wrongUserName();
}

void ExceptionGift::print()
{
	Viewer::getInstance()->unfoundGift();
}

void ExceptionComponent::print()
{
	Viewer::getInstance()->unfoundComponent();
}

void ExceptionRegistered::print()
{
	Viewer::getInstance()->allreadyRegistered();
}
