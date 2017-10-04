#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer
{
protected:
	vector<Subject*> presidentes;
};

class Subject
{
private:
	vector<Observer*> noticieros;
	string accion;

public:
	string getAccion() { return accion; }
	
	void setAccion(string n) 
	{
		accion = n;
	}

	void agregarObserver(Observer* ob) 
	{
		noticieros.push_back(ob);
	}
};

class MVSNoticias : public Observer
{
public:
	MVSNoticias(vector<Subject*> n)
	{
		presidentes = n;
	}
};

class TelevisaNoticias : public Observer
{
public:
	TelevisaNoticias(vector<Subject*> n)
	{
		presidentes = n;
	}
};

class RadioRealNoticias : public Observer
{
public:
	RadioRealNoticias(vector<Subject*> n)
	{
		presidentes = n;
	}
};

class NoticiasInternacionales : public Observer
{
public:
	NoticiasInternacionales(vector<Subject*> n)
	{
		presidentes = n;
	}
};

class Trump : public Subject
{

};

class Pena : public Subject
{

};

class KimJongUn : public Subject
{

};

int main()
{

}