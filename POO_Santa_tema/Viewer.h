#pragma once
#include"BD.h"
class Viewer
{
	static Viewer* instance;
	Viewer()=default;
	~Viewer()=default;
public:
	static Viewer* getInstance();
	static void destroyInstance();
	void startingScreen();
	void clear();

	void conectedScreen();
	void wrongUserName();
	void chooseAccount();
	void allreadyRegistered();
	void wrongPassword();
	void tooManyTries();

	void santaOptions();
	void printChildren();
	Copil* addChildScreen();
	string deleteChildScreen();
	string chooseChild();
	void modifyChildData(const Copil* copil);
	void unfoundGift();

	void elfOptions();
	void printGifts();
	void elfGiftOptions();
	Cadou* addGift();
	string chooseGift();
	void modifyGift(Cadou* cadou);
	void addComponentToGift(Cadou* cadou);
	void unfoundComponent();
	void elfComponentOptions();
	void printComponent();
	Component* addMotor();
	Component* addStandardComponent();
};

