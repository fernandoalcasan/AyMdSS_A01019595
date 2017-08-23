/*
Fernando Alcantara Santana A01019595
Singleton/Clock
23/08/2017
A01019595@itesm.mx
*/

#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* getInstance();
	void operacion();

private:
	Singleton() = default;

protected:
	static Singleton* instance;
};

Singleton * Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
	if (!instance)
	{
		instance = new Singleton;
	}
	return instance;
}

void Singleton::operacion()
{
	cout << "Dir de Sing:" << instance << endl;
}

int main(int argc, char** argv)
{
	Singleton * instance = Singleton::getInstance();
	instance->operacion();
	Singleton * instance2 = Singleton::getInstance();
	instance2->operacion();
	Singleton * instance3 = Singleton::getInstance();
	instance3->operacion();
	int a; //para que no me cierre la ventana emergente jajaja
	cin >> a;	//para que no me cierre la ventana emergente jajaja
}
