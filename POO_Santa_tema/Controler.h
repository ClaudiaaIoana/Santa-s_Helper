#pragma once
#include"MosCraciun.h"
#include"Spiridus.h"
#include"Copil.h"
#include<string>
using namespace std;
class Controler
{
	static Controler* instance;
	static MosCraciun* santaLogged;
	static Spiridus* spiridusLogged;
	static bool exited;
	Controler() = default;
	~Controler();
public:
	static Controler* getInstance();
	static void destroyInstance();
	void exit();
	void startApp();

	void getAccount();
	void chooseAccount();
	void makeSpiridusAccount();
	void makeMosAccount();
	string getPassword();
	bool retry();

	void santaOptions();
	void modifyKidData(string name);
	void changeKidAdress(Copil* copil);
	void giveGift(Copil*copil);
	void addWish(Copil* copil);

	void elfOptions();
	void elfGiftOptions();
	void addGift();
	void modifyGift();
	void addComponentToGift(Cadou*cadou);
	void elfComponentOptions();
	void addMotor();
	void addStandardComponent();
};

