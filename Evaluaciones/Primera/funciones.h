#include <iostream>
#include <string>

using namespace std;

class Computadora
{
public:
	void proceso(string p);
	string nombre;
	virtual Computadora* clone() = 0;

protected:
	Computadora() = default;
};

template<class SubCompu>
class clonComputadora : public Computadora
{
protected:
	clonComputadora() {}
public:
	Computadora* clone()
	{
		return new SubCompu(dynamic_cast<SubCompu&>(*this));
	}
};

class fabricaCompus
{
private:
	fabricaCompus() {}

public:
	static fabricaCompus* equipo;
	static fabricaCompus* nuevoEquipoFabrica();
	template<class Equipo>
	static Equipo* Creacion()
	{
		return new Equipo;
	}
};

fabricaCompus * fabricaCompus::equipo = 0;

fabricaCompus* fabricaCompus::nuevoEquipoFabrica()
{
	if (!equipo)
	{
		equipo = new fabricaCompus;
	}
	return equipo;
}

class Desktop : public clonComputadora<Desktop>
{
	friend class fabricaCompus;
private:
	Desktop() { nombre = "Desktop"; }
	Desktop(string s) {nombre = s;};
};

class Laptop : public clonComputadora<Laptop>
{
	friend class fabricaCompus;
private:
	Laptop() { nombre = "Laptop"; }
	Laptop(string s) {nombre = s;};
};

class Netbook : public clonComputadora<Netbook>
{
	friend class fabricaCompus;
private:
	Netbook() { nombre = "Netbook"; }
	Netbook(string s) {nombre = s;};
};

class Tablet : public clonComputadora<Tablet>
{
	friend class fabricaCompus;
private:
	Tablet() { nombre = "Tablet"; }
	Tablet(string s) {nombre = s;};
};

class ServerRack : public clonComputadora<ServerRack>
{
	friend class fabricaCompus;
private:
	ServerRack() { nombre = "Server(Rack)"; }
	ServerRack(string s) {nombre = s;};
};

class ServerTower : public clonComputadora<ServerTower>
{
	friend class fabricaCompus;
private:
	ServerTower() { nombre = "Server(Tower)"; }
	ServerTower(string s) {nombre = s;};
};

void Computadora::proceso(string p)
{
	cout << "Estoy en el proceso de selección de componentes de: " << p << endl;
	cout << "Estoy en el proceso de ensamblado de componentes de: " << p << endl;
	cout << "Estoy en el proceso de instalación y configuración de Software de: " << p << endl;
	cout << "Estoy en el proceso de empaquetado del Computador de: " << p << endl;
}