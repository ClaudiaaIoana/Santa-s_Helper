#include "BD.h"
#include"Logger.h"
#include"IException.h"
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

BD* BD::instance = nullptr;

BD::~BD()
{
    MosCraciun::deleteInstance();
}

BD* BD::getInstance()
{
    if (instance == nullptr)
    {
        instance = new BD();
    }
    return instance;
}

void BD::destroyInstance()
{
    if (instance)
        delete instance;
}

void BD::updateFiles()
{
    ofstream fout;
    fout.open("Conturi.txt");
    fout << mosCraciun;
    fout << spiridusi;
    fout.close();
    fout.clear();
    fout.open("Componente.txt");
    fout << componente;
    fout.close();
    fout.clear();
    fout.open("Cadouri.txt");
    fout << cadouri;
    fout.close();
    fout.clear();
    fout.open("Copii.txt");
    fout << copii;
    fout.close();
    fout.clear();
}

void BD::addNew(Copil* copil)
{
    copii.add(copil);

}

void BD::addNew(Cadou* cadou)
{
    cadouri.add(cadou);
}

void BD::addNew(Component* componenta)
{
    componente.add(componenta);
}

void BD::addNew(Cont* cont)
{
    if (dynamic_cast<Spiridus*>(cont))
        spiridusi.add(dynamic_cast<Spiridus*>(cont));
    if (dynamic_cast<MosCraciun*>(cont))
        mosCraciun = dynamic_cast<MosCraciun*>(cont);
}

void BD::readDataBase()
{
    ifstream fin;
    fin.open("Conturi.txt");
    if (!fin.is_open())
        throw ExceptionFile("Conturi.txt", 1);
    if (fin.peek() != ifstream::traits_type::eof())
    {
        string firstName;
        getline(fin, firstName,':');
        fin.clear();
        fin.seekg(0, ios::beg);
        if (firstName == "Santa Claus");
        {   
            mosCraciun = MosCraciun::getInstance();
            fin >> mosCraciun;
        }
        fin >> (&spiridusi);
    }
    fin.close();
    fin.clear();

    fin.open("Componente.txt");
    if (!fin.is_open())
        throw ExceptionFile("Componente.txt", 2);
    if (fin.peek() != ifstream::traits_type::eof())
    fin >> (&componente);
    fin.close();
    fin.clear();

    fin.open("Cadouri.txt");
    if (!fin.is_open())
        throw ExceptionFile("Cadouri.txt", 3);
    if (fin.peek() != ifstream::traits_type::eof())
    fin >> (&cadouri);
    fin.close();
    fin.clear();

    fin.open("Copii.txt");
    if (!fin.is_open())
        throw ExceptionFile("Copii.txt", 4);
    if (fin.peek() != ifstream::traits_type::eof())
    fin >> (&copii);
    fin.close();
    fin.clear();
}

void BD::deleteChild(string name)
{
    copii.deleteElement(name);
    Logger::getInstance()->deleteChild(getMosul(), name);
}

vector<Copil*>& BD::getCopii()
{
    return copii.getVector();
}

vector<Cadou*>& BD::getCadouri()
{
    return cadouri.getVector();
}

vector<Component*>& BD::getComponente()
{
    return componente.getVector();
}

MosCraciun* BD::getMosul()
{
    return mosCraciun;
}
