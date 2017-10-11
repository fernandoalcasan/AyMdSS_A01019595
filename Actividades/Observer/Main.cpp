#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer
{
public:
	virtual void noticia(string na, string no) = 0;
};

class MVSNoticias : public Observer
{
public:
	MVSNoticias() = default;
	void noticia(string na, string no)
	{
		cout << "MVS Noticias informa: " << na << " dijo que " << no << endl;
	}
};

class TelevisaNoticias : public Observer
{
public:
	TelevisaNoticias() = default;
	void noticia(string na, string no)
	{
		cout << "Televisa Noticias informa: " << na << " dijo que " << no << endl;
	}
};

class RadioRealNoticias : public Observer
{
public:
	RadioRealNoticias() = default;
	void noticia(string na, string no)
	{
		cout << "Radio Real Noticias informa: " << na << " dijo que " << no << endl;
	}
};

class NoticiasInternacionales : public Observer
{
public:
	NoticiasInternacionales() = default;
	void noticia(string na, string no)
	{
		cout << "Noticias Internacionales informa: " << na << " dijo que " << no << endl;
	}
};


class Subject
{
private:
	vector<Observer*> noticieros;
	
protected:
	string accion;
	string name;

public:
	Subject() = default;
	Subject(string a) : accion(a) {}
	string getAccion() { return accion; }
	string getNombre() { return name; }
	
	void setAccion(string a) 
	{
		accion = a;
	}

	void setNombre(string n)
	{
		name = n;
	}

	void agregarObserver(Observer* ob) 
	{
		noticieros.push_back(ob);
	}

	void Cajetearla(string c)
	{
		for (int i = 0; i < noticieros.size(); i++)
		{
			noticieros[i]->noticia(getNombre() , c);
		}
	}
};


class Trump : public Subject
{
public:
	Trump()
	{
		name = "Donald Trompetas";
	}
};

class Pena : public Subject
{
public:
	Pena()
	{
		name = "Peña Nieto";
	}
};

class KimJongUn : public Subject
{
public:
	KimJongUn()
	{
		name = "Kim Jong-Un";
	}
};

int main()
{
	Trump* trompetas = new Trump();
	Pena* penaAjena = new Pena();
	KimJongUn* kimLocoUn = new KimJongUn();
	MVSNoticias* mvs = new MVSNoticias();
	TelevisaNoticias* telenovelas = new TelevisaNoticias();
	RadioRealNoticias* rrn = new RadioRealNoticias();
	NoticiasInternacionales* ni = new NoticiasInternacionales();

	trompetas->agregarObserver(mvs);
	trompetas->agregarObserver(telenovelas);
	trompetas->agregarObserver(rrn);
	trompetas->agregarObserver(ni);

	trompetas->Cajetearla("Pueeeeerto Reeeeeeeeeeco will rise!");

	delete trompetas;
	delete penaAjena;
	delete kimLocoUn;
	delete mvs;
	delete telenovelas;
	delete rrn;
	delete ni;
}