#include "Controler.h"
#include"Spiridus.h"
#include"Viewer.h"
#include"BD.h"
#include"Logger.h"
#include"IException.h"
#include<iostream>
#include<string>;
#include<conio.h>
using namespace std;

Controler* Controler::instance = nullptr;
MosCraciun* Controler::santaLogged = nullptr;
Spiridus* Controler::spiridusLogged = nullptr;
bool Controler::exited = false;

Controler::~Controler()
{
    santaLogged = nullptr;
    spiridusLogged = nullptr;
    if (!exited)
        exit();
}

Controler* Controler::getInstance()
{
    if (!instance)
        instance = new Controler();
    return instance;
}

void Controler::destroyInstance()
{
    if (instance)
        delete instance;
}

void Controler::exit()
{
    BD* bd = BD::getInstance();
    bd->updateFiles();
    BD::destroyInstance;
    Viewer::destroyInstance();
    Logger::destroyLogger();
    exited = true;
}

void Controler::getAccount()
{
    BD* bd = BD::getInstance();
    Viewer* view = Viewer::getInstance();
    string nume;
    string password;
    reEnterUser:
    view->clear();
    cout << "\t\t\t\tName: ";
    getline(cin, nume);
    if(nume=="")
        getline(cin, nume);
    Spiridus* spiridus = bd->searchSpiridus(nume);
    tryAgain:
    password = getPassword();
    try {
        if (spiridus)
        {
            if (!spiridus->verificareParola(password))
            {
                throw ExceptionPassword();
            }
            spiridusLogged = spiridus;
        }
        else if (nume == "Santa Claus" && bd->getMosul())
        {

            if (!bd->getMosul()->verificareParola(password))
            {
                throw ExceptionPassword();
            }
            santaLogged = bd->getMosul();
        }
        else
        {
            throw ExceptionUsser();
        }
    }
    catch (ExceptionPassword &e)
    {
        if (e.handle())
        {
            e.print();
            cout<< "\t\t\t\tName: "<<nume<<endl;
            goto tryAgain;
        }
        else
            view->tooManyTries();
    }
    catch (ExceptionUsser& e)
    {
        e.print();
        if (retry())
            goto reEnterUser;
    }

}

void Controler::chooseAccount()
{
    char key;
    pressKey:
    key = _getch();
    switch (key)
    {
    case '1':
        makeMosAccount();
        break;
    case '2':
        makeSpiridusAccount();
        break;
    others:
        goto pressKey;
        break;
    }
}

void Controler::makeSpiridusAccount()
{
    Viewer* view = Viewer::getInstance();
    view->clear();
    string name;
    string password;
    cout << endl << endl << endl << endl;
    cout << "\t\t\t\tHELLO, DEAR ELF! PLEASE ENTER YOUR:" << endl;
    cout << "\t\t\t\tName: ";
    cin >> name;
    try {
        if (BD::getInstance()->searchSpiridus(name))
        {
            throw ExceptionRegistered();
           
        }
        password = getPassword();
        cin.ignore();
        Spiridus* spiridus = new Spiridus(name, password);
        BD::getInstance()->addNew(spiridus);
        Logger::getInstance()->madeAccount(spiridus);
        BD::getInstance()->updateFiles();
    }
    catch (ExceptionRegistered& e)
    {
        e.print();
    }
    view->startingScreen();
}

void Controler::makeMosAccount()
{
    Viewer* view = Viewer::getInstance();
    view->clear();
    BD* bd = BD::getInstance();
    try {
        if (bd->getMosul())
            throw ExceptionRegistered();
        cout << "\t\t\t\tHELLO, DEAR SANTA! PLEASE ENTER YOUR:" << endl;
        string password = getPassword();
        cin.ignore();
        MosCraciun* mosul = MosCraciun::getInstance(password);
        bd->addNew(mosul);
        Logger::getInstance()->madeAccount(mosul);
        bd->updateFiles();
    }
    catch (ExceptionRegistered& e)
    {
        e.print();
    }

}

string Controler::getPassword()
{
    string password;
    cout << "\t\t\t\tPassword: ";
    char key = _getch();
    while (key != '\r')
    {
        cout << "$";
        password += key;
        key = _getch();
    }
    return password;
}

void Controler::startApp()
{
    BD* bd = BD::getInstance();
    Viewer* view = Viewer::getInstance();
    Logger* logger = Logger::getInstance();
    bd->readDataBase();
    view->startingScreen();

    char comand;
    comand = '0';
    while (comand != '3')
    {
        view->startingScreen();
        comand = _getch();
        switch (comand)
        {
        case '1':
            getAccount();
            if (santaLogged)
            {
                logger->loggedIn(santaLogged);
                santaOptions();
            }
            else if (spiridusLogged)
            {
                logger->loggedIn(spiridusLogged);
                elfOptions();
            }
            break;
        case '2':
            view->chooseAccount();
            chooseAccount();
            break;
        case '3':
            exit();
            break;
        others:
            break;
        }
    }
}

bool Controler::retry()
{
    char key;
    key = _getch();
    while (true)
    {
        if (key == '1')
            return true;
        if (key == '2')
            return false;
        key = _getch();
    }
}

void Controler::santaOptions()
{
    Viewer* view = Viewer::getInstance();
    BD* bd = BD::getInstance();
    Copil* copil;
    string name;
    char key = '0';
    while (key != '4')
    {
        view->santaOptions();
        key = _getch();
        switch (key)
        {
        case'1':
            copil = view->addChildScreen();
            bd->addNew(copil);
            Logger::getInstance()->addChild(santaLogged, copil);
            bd->updateFiles();
            break;
        case '2':
            name = view->deleteChildScreen();
            bd->deleteChild(name);
            bd->updateFiles();
            break;
        case '3':
            modifyKidData(view->chooseChild());
            break;
        case '4':
            Logger::getInstance()->loggedOut(santaLogged);
            santaLogged = nullptr;
            break;
        others:
            break;
        }
        bd->updateFiles();
    }
}

void Controler::modifyKidData(string name)
{
    BD* bd = BD::getInstance();
    Viewer* view = Viewer::getInstance();
    Logger* logger = Logger::getInstance();
    Copil* copil = bd->searchCopil(name);

    //to do exceptii

    if (copil == nullptr)
        return;
    view->modifyChildData(copil);
    char key='0';
    while (key != '5')
    {
        view->modifyChildData(copil);
        key = _getch();
        switch (key)
        {
        case '1':
            giveGift(copil);
            logger->gaveGift(santaLogged, copil);
            break;
        case '2':
            addWish(copil);
            logger->addWish(santaLogged, copil);
            break;
        case '3':
            changeKidAdress(copil);
            logger->changeAdress(santaLogged, copil);
            break;
        case '4':
            copil->changeStatus();
            logger->changeStatus(santaLogged, copil);
            break;
        case'5':
            break;
        others:
            break;
        }
        bd->updateFiles();
    }
}

void Controler::changeKidAdress(Copil* copil)
{
    Viewer::getInstance()->clear();
    copil->printForDisplay();
    cout << endl << "\t\t\t\tEnter Adress: ";
    string adress;
    getline(cin, adress);
    copil->changeCurrentAdress(adress);
}

void Controler::giveGift(Copil* copil)
{
    Viewer::getInstance()->clear();
    copil->printForDisplay();
    cout << endl << "\t\t\t\tGIVE A GIFT " << endl << "\t\t\t\tEnter the gift: ";
    string gift;
    getline(cin, gift);
    Cadou* cadou = BD::getInstance()->searchCadou(gift);

    try {
        if (cadou == nullptr)
        {
            throw ExceptionGift();
        }
        copil->addCadouPrimit(cadou->getID());
    }
    catch (ExceptionGift &e)
    {
        e.print();
    }
}

void Controler::addWish(Copil* copil)
{
    copil->printForDisplay();
    cout << endl << "\t\t\t\tADD NEW WISH" << endl << "\t\t\t\tEnter the gift: ";
    string gift;
    getline(cin, gift);
    Cadou* cadou = BD::getInstance()->searchCadou(gift);

    try {
        if (cadou == nullptr)
        {
            throw ExceptionGift();
        }
        copil->addCadouDorit(cadou->getID());
    }
    catch (ExceptionGift& e)
    {
        Viewer::getInstance()->unfoundGift();
    }
}

void Controler::elfOptions()
{
    Viewer* view = Viewer::getInstance();
    BD* bd = BD::getInstance();
    char key = '0';
    while (key != '3')
    {
        view->elfOptions();
        key = _getch();
        switch (key)
        {
        case'1':
            elfGiftOptions();
            break;
        case '2':
            elfComponentOptions();
            break;
        case '3':
            Logger::getInstance()->loggedOut(spiridusLogged);
            spiridusLogged = nullptr;
            break;
        others:
            break;
        }
    }
}

void Controler::elfGiftOptions()
{
    Viewer* view = Viewer::getInstance();
    view->elfGiftOptions();
    BD* bd = BD::getInstance();
    char key = '0';
    while (key != '3')
    {
        view->elfGiftOptions();
        key = _getch();
        switch (key)
        {
        case'1':
            addGift();
            break;
        case '2':
            modifyGift();
            break;
        case '3':
            break;
        others:
            break;
        }
    }
}

void Controler::addGift()
{
    Cadou* cadou = Viewer::getInstance()->addGift();
    BD::getInstance()->addNew(cadou);
    Logger::getInstance()->madeGift(spiridusLogged, cadou);

    BD::getInstance()->updateFiles();

}

void Controler::modifyGift()
{
    BD* bd = BD::getInstance();
    Viewer* view = Viewer::getInstance();
    Logger* logger = Logger::getInstance();
    Cadou*cadou = bd->searchCadou(view->chooseGift());


    try {
        if (cadou == nullptr)
            throw ExceptionGift();
   
    char key = '0';
    while (key != '3')
    {
        view->modifyGift(cadou);
        key = _getch();
        switch (key)
        {
        case '1':
            addComponentToGift(cadou);
            logger->addedCompToGift(spiridusLogged, cadou);
            break;
        case '2':
            cadou->changePackage();
            logger->changePackage(spiridusLogged, cadou);
            break;
        case '3':
            break;
        others:
            break;
        }
        bd->updateFiles();
    }
    }
    catch (ExceptionGift& e)
    {
        view->unfoundGift();
    }
}

void Controler::addComponentToGift(Cadou* cadou)
{
    Viewer* view = Viewer::getInstance();
    BD* bd = BD::getInstance();
    view->addComponentToGift(cadou);
    string comp;
    cin >> comp;
    Component* componenta = bd->searchComponenta(comp);

    try {
        if (componenta == nullptr)
        {
            view->unfoundComponent();
            throw ExceptionComponent();
        }
        cadou->addComponent(componenta->getID());
    }
    catch (ExceptionComponent& e)
    {
        e.print();
    }
}

void Controler::elfComponentOptions()
{
    Viewer* view = Viewer::getInstance();
    view->elfComponentOptions();
    BD* bd = BD::getInstance();
    char key = '0';
    while (key != '3')
    {
        view->elfComponentOptions();
        key = _getch();
        switch (key)
        {
        case'1':
            addStandardComponent();
            break;
        case '2':
            addMotor();
            break;
        case '3':
            break;
        others:
            break;
        }
        bd->updateFiles();
    }
}

void Controler::addMotor()
{
    Component* motor = Viewer::getInstance()->addMotor();
    BD::getInstance()->addNew(motor);
    Logger::getInstance()->madeComponent(spiridusLogged, motor);
}

void Controler::addStandardComponent()
{
    Component* comp = Viewer::getInstance()->addStandardComponent();
    BD::getInstance()->addNew(comp);
    Logger::getInstance()->madeComponent(spiridusLogged, comp);
}


