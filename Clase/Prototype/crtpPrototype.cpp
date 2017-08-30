#include <iostream>
#include <string>

using namespace std;

class Mundo
{
public:
	Mundo(string nm) : nombreMundo(nm) {}
	string nombreMundo;
};

class Personaje
{
public:
	Personaje() = default;
	Personaje(string nombre) : nombre(nombre) {}
	string nombre;
	int telefono;
	Mundo* mundo;
	string correo;
	virtual Personaje* clone() = 0;
};

template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
	Personaje* clone()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class Princesa : public ClonPersonaje<Princesa>
{
public:
	Princesa(string n)
	{
		nombre = n;
	}
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
};

int main()
{
	Princesa* pri = new Princesa("Rapunzel");
	pri->correo = "princesitamoribunda@tec.mx";
	pri->telefono = 1111111111;
	pri->mundo = new Mundo("Paleta");
	Princesa* p = dynamic_cast<Princesa*>(pri->clone());
	pri->nombre = "RAPUNZEL";
	pri->mundo->nombreMundo = "Paleton";
	cout << p->nombre << endl;
	cout << p->correo << endl;
	cout << p->telefono << endl;

	Princesa* pp = dynamic_cast<Princesa*>(p->clone());
	pp->mundo->nombreMundo = "Paletita";

	int a; //Para que no se cierre la ventana en VS
	cin >> a;	//Para que no se cierre la ventana en VS
}