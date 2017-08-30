#include <iostream>
#include <string>

using namespace std;

class Mundo
{
public:
	Mundo(string nm) : nombreMundo(nm){}
	string nombreMundo;
};

class Personaje
{
public:
	Personaje() = default;
	Personaje(string nombre) : nombre(nombre){}
	string nombre;
	int telefono;
	Mundo* mundo;
	string correo;
	virtual Personaje* clone() = 0;
};

class Princesa : public Personaje
{
public:
	Princesa(string n) : Personaje(n){}
	Princesa(const Princesa& p) 
	{
		nombre = p.nombre;
		telefono = p.telefono;
		mundo = new Mundo(p.mundo->nombreMundo);
		correo = p.correo;
	}
	void grita() 
	{
		cout << "aaaaaaaaaaa" << endl;
	}
	Personaje* clone()
	{
		return new Princesa(*this);
	}
};

class Villano : public Personaje
{
public:
	Villano(string n) : Personaje(n) {}
	Villano(const Villano& p)
	{
		nombre = p.nombre;
		telefono = p.telefono;
		mundo = new Mundo(p.mundo->nombreMundo);
		correo = p.correo;
	}
	void secuestra()
	{
		cout << "te atrapé!" << endl;
	}
	Personaje* clone()
	{
		return new Villano(*this);
	}
};

class Heroe : public Personaje
{
public:
	Heroe(string n) : Personaje(n) {}
	Heroe(const Heroe& p)
	{
		nombre = p.nombre;
		telefono = p.telefono;
		mundo = new Mundo(p.mundo->nombreMundo);
		correo = p.correo;
	}
	void salvar()
	{
		cout << "yo te rescaté!" << endl;
	}
	Personaje* clone()
	{
		return new Heroe(*this);
	}
};

int main()
{
	Princesa* pri = new Princesa("Rapunzel");
	pri->correo = "princesitamoribunda@tec.mx";
	pri->telefono = 1111111111;
	pri->mundo = new Mundo("Paleta");
	//Personaje* p = pri->clone();
	//También se puede así
	Princesa* p = dynamic_cast<Princesa*>(pri->clone());
	pri->nombre = "RAPUNZEL";
	pri->mundo->nombreMundo = "Paleton";
	cout << p->nombre << endl;
	cout << p->correo << endl;
	cout << p->telefono << endl;
	cout << p->mundo->nombreMundo << endl;

	int a; //Para que no se cierre la ventana en VS
	cin >> a;	//Para que no se cierre la ventana en VS
}