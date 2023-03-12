#pragma once
#include<string>
using namespace std;
__interface IException
{
public:
	virtual void print()=0;
};
class ExceptionFile :public IException
{
	string mesaj;
	int cod;
public:
	ExceptionFile(string mesaj, int cod);
	void print();
};

class ExceptionGift :public IException
{
public:
	void print() override;
};

class ExceptionPassword:public IException
{
	static int tries;
public:
	ExceptionPassword();
	bool handle();
	void print() override;
};
class ExceptionUsser :public IException
{
public:
	void print()override;
};
class ExceptionComponent: public IException
{
public:
	void print() override;
};

class ExceptionRegistered : public IException
{
public: 
	void print();
};