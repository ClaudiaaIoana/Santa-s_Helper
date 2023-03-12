#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"Copil.h"
#include"Cadou.h"
#include"Componenta.h"
#include"Spiridus.h"
#include"MosCraciun.h"
#include"Tabela.h"
using namespace std;
class BD
{
	static BD* instance;
	Tabela<Copil> copii;
	Tabela<Cadou> cadouri;
	Tabela<Component> componente;
	Tabela<Spiridus> spiridusi;
	MosCraciun* mosCraciun=nullptr;

	BD()=default;
	~BD();
public:
	static BD* getInstance();
	static void destroyInstance();
	void updateFiles();
	void addNew(Copil* copil);
	void addNew(Cadou* cadou);
	void addNew(Component* componenta);
	void addNew(Cont* cont);
	void readDataBase();
	void deleteChild(string name);
	vector<Copil*>& getCopii();
	vector<Cadou*>& getCadouri();
	vector<Component*>& getComponente();
	template<class T>
	Spiridus* searchSpiridus(T identificator);
	template<class T>
	Copil* searchCopil(T identificator);
	template<class T>
	Cadou* searchCadou(T identificator);
	template<class T>
	Component* searchComponenta(T identificator);
	MosCraciun* getMosul();
};

template<class T>
inline Spiridus* BD::searchSpiridus(T identificator)
{
	return spiridusi.find(identificator);
}

template<class T>
inline Copil* BD::searchCopil(T identificator)
{
	return copii.find(identificator);
}

template<class T>
inline Cadou* BD::searchCadou(T identificator)
{
	return cadouri.find(identificator);
}

template<class T>
inline Component* BD::searchComponenta(T identificator)
{
	return componente.find(identificator);
}
