#pragma once
#include"Cont.h"
class MosCraciun:public Cont
{
	static MosCraciun* instance;
	MosCraciun() = default;
	MosCraciun(string parola);
	~MosCraciun();
public:
	static MosCraciun* getInstance();
	static MosCraciun* getInstance(string parola);
	static void deleteInstance();
};

