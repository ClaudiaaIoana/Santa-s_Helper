#pragma once
#include<string>
#include<iostream>
#include<conio.h>
using namespace std;
class Cont
{
	string utilizator;
	string parola;
public:
	Cont() = default;
	Cont(string utilizator,string parola);
	virtual ~Cont();
	string getNume();
	bool verificareParola(string parola);
	friend ostream& operator<<(ostream& out, Cont* cont);
	friend istream& operator>>(istream& in, Cont* cont);
};

