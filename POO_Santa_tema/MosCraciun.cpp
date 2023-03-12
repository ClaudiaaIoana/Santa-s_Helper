#include "MosCraciun.h"
#include<iostream>
using namespace std;

MosCraciun* MosCraciun:: instance = nullptr;

MosCraciun::MosCraciun(string parola)
	:Cont("Santa Claus",parola)
{
	instance = nullptr;
}

MosCraciun::~MosCraciun()
{
}

MosCraciun* MosCraciun::getInstance()
{
	if (!instance)
	{
		instance = new MosCraciun();
	}
	return instance;
}

MosCraciun* MosCraciun::getInstance(string parola)
{
	if (!instance)
	{
		instance = new MosCraciun(parola);
	}
	return instance;
}

void MosCraciun::deleteInstance()
{
	if (instance)
		delete instance;
}
