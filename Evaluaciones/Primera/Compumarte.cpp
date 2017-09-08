#include "funciones.h"

using namespace std;

int main()
{
	//Singleton
	fabricaCompus* Compumarte = fabricaCompus::nuevoEquipoFabrica();

	int res;
	cout << "Ingresa el tipo de computadora a crear: 1.Desktop  2.Laptop  3.Netbook 4.Tablet 5.Server(Rack) 6.Server(Tower)\n";
	cin >> res;
	
	switch (res)
	{
		case 1:
		{
			//FactoryMethod
			Desktop* nuevo = Compumarte->Creacion<Desktop>();
			nuevo->proceso("Desktop");
			//SI fuera por CRTP
			//Desktop* nuevo2 = dynamic_cast<Desktop*>(nuevo->clone());
			//nuevo2->proceso("Desktop");
			delete nuevo;
			break;
		}
		case 2:
		{
			Laptop* nuevo = Compumarte->Creacion<Laptop>();
			nuevo->proceso("Laptop");
			delete nuevo;
			break;
		}
		case 3:
		{
			Netbook* nuevo = Compumarte->Creacion<Netbook>();
			nuevo->proceso("Netbook");
			delete nuevo;
			break;
		}
		case 4:
		{
			Tablet* nuevo = Compumarte->Creacion<Tablet>();
			nuevo->proceso("Tablet");
			delete nuevo;
			break;
		}
		case 5:
		{
			ServerRack* nuevo = Compumarte->Creacion<ServerRack>();
			nuevo->proceso("Server (Rack)");
			delete nuevo;
			break;
		}
		case 6:
		{
			ServerTower* nuevo = Compumarte->Creacion<ServerTower>();
			nuevo->proceso("Server (Tower)");
			delete nuevo;
			break;
		}
		default:
			cout << "Seleccione una opción correcta por favor! Adiós!" << endl;
			break;
	}

	delete Compumarte;
	return 0;
}