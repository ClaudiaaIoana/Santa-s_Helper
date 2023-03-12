#pragma once
#include"MotorMasinuta.h"
#include"StdComponent.h"
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
template<class T>
class Tabela
{
	vector<T*> elemente;
public:
	~Tabela();
	void add(T* element);
	T* find(int ID);
	T* find(string nume);
	vector<T*>& getVector();
	void deleteElement(string name);
	template<class T>
	friend ostream& operator<<(ostream& out, Tabela<T>& tabela);
	template<class T>
	friend istream& operator>>(istream& in, Tabela<T> tabela);
};

template<class T>
inline Tabela<T>::~Tabela()
{
	for (auto it = elemente.begin(); it != elemente.end(); it++)
		delete (*it);
}

template<class T>
inline void Tabela<T>::add(T* element)
{
	elemente.push_back(element);
}

template<class T>
inline T* Tabela<T>::find(int ID)
{
	for (auto it = elemente.begin(); it != elemente.end(); it++)
	{
		if((*it)->getID()==ID)
			return *it;
	}
	return nullptr;
}

template<class T>
inline T* Tabela<T>::find(string nume)
{
	for (auto it = elemente.begin(); it != elemente.end(); it++)
	{
		if ((*it)->getNume() == nume)
			return *it;
	}
	return nullptr;
}

template<class T>
inline vector<T*>& Tabela<T>::getVector()
{
	return elemente;
}

template<class T>
inline void Tabela<T>::deleteElement(string name)
{
	for (auto it = this->elemente.begin(); it != this->elemente.end(); it++)
	{
		if ((*it)->getNume() == name)
		{
			T* element=(*it);
			this->elemente.erase(it);
			delete element;
			break;
		}
	}
}

template<class T>
inline ostream& operator<<(ostream& out, Tabela<T>& tabela)
{
	for (auto it = tabela.elemente.begin(); it != tabela.elemente.end(); it++)
		out << (*it);
	return out;
}

template<class T>
inline istream& operator>>(istream& in, Tabela<T>* tabela)
{
	T* element=nullptr;
	element = new T();
	while (in.peek() != ifstream::traits_type::eof())
	{
		in >> element;
		tabela->add(element);
		element = nullptr;
		element = new T();
	}
	delete element;
	return in;
}

template<>
inline istream& operator>>(istream& in, Tabela<Component>* tabela)
{
	Component* element = nullptr;
	string className;
	while (in.peek() != ifstream::traits_type::eof())
	{
		in >> className;
		if (className == "MotorMasinuta:")
			element = ComponentFactory::makeMotor();
		if (className == "StdComponent:")
			element = ComponentFactory::makeStandardComponent();
		in >> element;
		tabela->add(element);
		element = nullptr;
	}
	return in;
}

