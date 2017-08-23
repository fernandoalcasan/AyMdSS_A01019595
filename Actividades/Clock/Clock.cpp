/*
Fernando Alcantara Santana A01019595
Singleton/Clock
23/08/2017
A01019595@itesm.mx
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <ctime>

using namespace std;

class Clock
{
public:
	static Clock* getInstance();
	void operacion();

private:
	Clock() = default;

protected:
	static Clock* instance;
};

Clock * Clock::instance = 0;

Clock* Clock::getInstance()
{
	if (!instance)
	{
		instance = new Clock;
	}
	return instance;
}

void Clock::operacion()
{
	time_t FH = time(nullptr);
	cout << "Fecha y Hora: " << ctime(&FH) << endl;
}

int main(int argc, char** argv)
{
	Clock * instance = Clock::getInstance();
	instance->operacion();
	int a; //para que no me cierre la ventana emergente jajaja
	cin >> a;	//para que no me cierre la ventana emergente jajaja
}