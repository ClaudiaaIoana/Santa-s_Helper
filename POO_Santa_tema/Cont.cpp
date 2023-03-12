#include "Cont.h"

Cont::Cont( string utilizator,string parola)
	:parola(parola),utilizator(utilizator)
{
}

Cont::~Cont()
{
}

string Cont::getNume()
{
	return utilizator;
}

bool Cont::verificareParola(string parola)
{
	if (this->parola == parola)
		return true;
	return false;
}

ostream& operator<<(ostream& out, Cont* cont)
{
	out << cont->utilizator << ": " << cont->parola<<endl;
	return out;
}

istream& operator>>(istream& in, Cont* cont)
{
	string name;
	string password;
	getline(in, name, ':');
	getline(in, password);
	password = password.substr(1, password.length());
	cont->utilizator = name;
	cont->parola = password;
	return in;
}
