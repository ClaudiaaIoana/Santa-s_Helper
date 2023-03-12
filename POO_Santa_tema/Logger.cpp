#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include"IException.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<chrono>

Logger* Logger::instance = nullptr;

Logger::Logger()
{
	fout.open("Actions.log", ios_base::app);
	if (!fout.is_open())
		throw ExceptionFile("Actions.log", 5);
}

Logger::~Logger()
{
	fout.close();
}

Logger* Logger::getInstance()
{
	if (instance == nullptr)
		instance = new Logger();
	return instance;
}

void Logger::destroyLogger()
{
	delete instance;
}

void Logger::showTime()
{
	auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
	fout << ctime(&givemetime);
}

void Logger::madeAccount(Cont* cont)
{
	showTime();
	fout << "< " << cont->getNume() << " > " << "made a new account"<<endl<<endl;
}

void Logger::loggedIn(Cont* cont)
{
	showTime();
	fout << " < " << cont->getNume() << " > logged in" << endl<<endl;
}

void Logger::addChild(Cont* cont,Copil* copil)
{
	showTime();
	fout << " < " << cont->getNume() << " > " << "added "<< copil->getNume()<< endl<<endl;
}

void Logger::deleteChild(Cont* cont, string copil)
{
	showTime();
	fout << " < " << cont->getNume() << " > " << "deleted "<<copil << endl<<endl;
}

void Logger::changeAdress(Cont* cont, Copil* copil)
{
	showTime();
	fout << " < " << cont->getNume() << " > modified the adress of " << copil->getNume() << endl<<endl;
}

void Logger::changeStatus(Cont* cont, Copil* copil)
{
	showTime();
	fout << " < " << cont->getNume() << " > " << "change behavior status of " << copil->getNume() << endl<<endl;
}

void Logger::gaveGift(Cont* cont, Copil* copil)
{
	showTime();
	fout << " < " << cont->getNume() << " > " << "gave a gift to " << copil->getNume() << endl<<endl;
}

void Logger::addWish(Cont* cont, Copil* copil)
{
	showTime();
	fout << " < " << cont->getNume() << " > " << "added " << copil->getNume()<<"'s new wish" << endl<<endl;
}

void Logger::madeGift(Cont* cont, Cadou* cadou)
{
	showTime();
	fout << " < " << cont->getNume() << " > made the Gift " << cadou->getNume()<<endl<<endl;
}

void Logger::addedCompToGift(Cont* cont, Cadou* cadou)
{
	showTime();
	fout << " < " << cont->getNume() << " > added a component to " << cadou->getNume() << endl<<endl;
}

void Logger::changePackage(Cont* cont, Cadou* cadou)
{
	showTime();
	fout << " < " << cont->getNume() << " > changes the packaging of " << cadou->getNume() << endl<<endl;
}

void Logger::madeComponent(Cont* cont, Component* component)
{
	showTime();
	fout << " < " << cont->getNume() << " > made a new component: " << component->getNume() << endl<<endl;
}

void Logger::loggedOut(Cont* cont)
{
	showTime();
	fout << " < " << cont->getNume() << " > logged out" << endl<<endl;
}
