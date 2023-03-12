#pragma once
#include<iostream>
#include<fstream>
#include"Cont.h"
#include"Copil.h"
#include"Cadou.h"
#include"Componenta.h"
using namespace std;
class Logger
{
	static Logger* instance;
	ofstream fout;
	Logger();
	~Logger();
public:
	static Logger* getInstance();
	static void destroyLogger();
	void showTime();
	void madeAccount(Cont* cont);
	void loggedIn(Cont* cont);
	void addChild(Cont* cont,Copil*copil);
	void deleteChild(Cont* cont, string copil);
	void changeAdress(Cont* cont, Copil* copil);
	void changeStatus(Cont* cont, Copil* copil);
	void gaveGift(Cont* cont, Copil* copil);
	void addWish(Cont* cont, Copil* copil);
	void madeGift(Cont* cont, Cadou* cadou);
	void addedCompToGift(Cont* cont, Cadou* cadou);
	void changePackage(Cont* cont, Cadou* cadou);
	void madeComponent(Cont* cont, Component* component);
	void loggedOut(Cont* cont);
};

