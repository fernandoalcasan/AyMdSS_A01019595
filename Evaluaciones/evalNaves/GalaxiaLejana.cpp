//Fernando Alcantara Santana A01019595 ITC11
//Analysis and modelling of software systems TC2004
//25/10/2017
//2nd Partial Exam

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Universo[5][5] = { 0 };	//Tablero global donde se llevará a cabo el juego
bool Colisiones[5][5] = { false };	//Tablero que guardará las colisiones del sistema

template<class NEUTRO>	//Pre declaración de clase y template
class objectIterator;

class naveChismosa
{
public:
	naveChismosa() {}
	static naveChismosa* getNaveChismosa();
	void setColision(int x, int y) { Colisiones[x][y] = true; }
	void noticia(string objeto, int modo, int x, int y)
	{
		cout << "La Nave Chismosa informa: ";
		if (modo == 1)
			cout << objeto << " ha chocado en el punto [" << x << "][" << y << "]" << endl;
		else
			cout << "Tras revisar los desastres en el punto [" << x << "][" << y << "]" << " se encontro que " << objeto << " estuvo involucrado tambien en el choque!" << endl;
		cout << "Tome precauciones, por fa!\n" << endl;
		setColision(x, y);
	}

protected:
	static naveChismosa* instance;
};

naveChismosa* naveChismosa::instance = 0;

naveChismosa* naveChismosa::getNaveChismosa()
{
	if (!instance)
		instance = new naveChismosa();
	return instance;
}

void imprimeMapaColisiones()
{
	cout << "\n||||||||||||||||||||||||||||MAPA DE COLISIONES FINAL||||||||||||||||||||||||||||\n" << endl;
	cout << "||||||||||||||||||||||||||||Mapa de [0][0] a [4][4]||||||||||||||||||||||||||||\n" << endl;
	for (int i = 4; i > -1; i--)
	{
		cout << "\nSector " << i << " --> ";
		for (int j = 0; j < 5; j++)
		{
			if (Colisiones[j][i] == true)
				cout << "| X |";
			else
				cout << "| O |";
		}
	}
}

class Objeto
{
protected:
	string tipo;
	int posX;
	int posY;
	bool existe;

public:
	void chocar(int modo, int x, int y);
	string getTipo() { return tipo; }
	void setTipo(string t) { tipo = t; }
	int getPosicionX() { return posX; }
	int getPosicionY() { return posY; }
	void setPosicionX(int x) { posX = x; }
	void setPosicionY(int y) { posY = y; }
	void setPosicion(int x, int y) { posX = x; posY = y; }
	naveChismosa* noticiero;
	void setNoticiero(naveChismosa* noti) { noticiero = noti; }
	bool getExistencia() { return existe; }
	void setExistencia(bool b) { existe = b; }

protected:
	Objeto() = default;
	Objeto(string a, int x, int y);
};

Objeto::Objeto(string a, int x, int y)
{
	existe = true;
	tipo = a;
	posX = x;
	posY = y;
}

void Objeto::chocar(int modo, int x, int y)
{
	noticiero->noticia(tipo, modo, x, y);
	setExistencia(false);
}

bool compruebaCasilla(int x, int y) //Función para comprobar que la casilla no ha tenido un choque y haya sido eliminada
{
	if (Universo[x][y] >= 2)
		return false;
	return true;
}

bool moverse(Objeto* o)
{
	if (!o->getExistencia()) //Si la nave ya no existe
		return false;
	else
		cout << "TURNO DE : " << o->getTipo() << " en la posicion " << " [" << o->getPosicionX() << "][" << o->getPosicionY() << "]" << endl;
	
	if (!compruebaCasilla(o->getPosicionX(), o->getPosicionY()))	//si la nave chocó cuando no se estaba moviendo
	{
		o->chocar(2, o->getPosicionX(), o->getPosicionY());
		return false;
	}

	bool mover = false;
	int provX, provY, dir;

	while (!mover)
	{
	    dir = rand() % 4 + 1;
		provX = o->getPosicionX();
		provY = o->getPosicionY();

		if (dir == 1 && provY < 4)	//Mover arriba con límite en 4
		{
			provY += 1;
			mover = true;
		}
		else if (dir == 2 && provX < 4)	//Mover derecha con límite en 4
		{
			provX += 1;
			mover = true;
		}	
		else if (dir == 3 && provY > 0)	//Mover abajo con límite en 0
		{
			provY -= 1;
			mover = true;
		}
		else if (dir == 4 && provX > 0)	//Mover izquierda con límite en 0
		{
			provX -= 1;
			mover = true;
		}
	}

	if (compruebaCasilla(provX, provY)) //Si la casilla no ha sido destruida por choque
	{
		Universo[o->getPosicionX()][o->getPosicionY()] = 0;
		cout << o->getTipo() << " se ha movido de [" << o->getPosicionX() << "][" << o->getPosicionY() << "] a [" << provX << "][" << provY << "]\n" << endl;
		o->setPosicion(provX, provY);
		Universo[o->getPosicionX()][o->getPosicionY()] += 1;
		if (!compruebaCasilla(o->getPosicionX(), o->getPosicionY())) //Si hubo un choque durante el nuevo movimiento
		{
			o->chocar(1, o->getPosicionX(), o->getPosicionY());
			return false;
		}
	}
	else
	{
		cout << o->getTipo() << " no se puede mover hacia " << dir << endl;
		cout << "Este turno permanecera parado!\n" << endl;
	}
	return true;
}

template<class NEUTRO>
class ObjetoColl
{
protected:
	NEUTRO* Objetos;
	int tama;
	int cont;
public:
	friend class objectIterator<NEUTRO>;
	objectIterator<NEUTRO>* getIterator() { return new objectIterator<NEUTRO>(*this); }
	NEUTRO at(int pos) { return Objetos[pos]; }

	ObjetoColl()
	{
		tama = 3;
		Objetos = new NEUTRO[tama];
		cont = 0;
	}

	void agregaObjeto(NEUTRO obj)
	{
		if (cont <= tama)
		{
			Objetos[cont++] = obj;
			return;
		}
		cout << "ya no caben más objetos en este universo Karnal!" << endl;
	}
};

template<class NEUTRO>
class objectIterator
{
protected:
	ObjetoColl<NEUTRO> coll;
	int cont = 0;

public:
	objectIterator(const ObjetoColl<NEUTRO>& coll) : coll(coll) {}
	int getContador() { return cont; }
	void reiniciarContador() { cont = 0; }
	NEUTRO next() { return coll.at(cont++); }

	bool hasNext()
	{
		if (cont < coll.tama)
			return true;
		return false;
	}
};

template<class NEUTRO, class Function>
void iniciarJuego(objectIterator<NEUTRO*>* ite, Function func)
{
	int objetos = 3;
	while (ite->hasNext())
	{
		NEUTRO* n = ite->next();
		
		if (!func(n))
			objetos--;

		if (objetos <= 1)	//Si el juego se ha quedado con un solo elemento (Nave, Asteroide o Planeta) o sin ninguno de ellos
		{
			cout << "El juego ha terminado!" << endl;
			return;
		}
		
		if (ite->getContador() >= 3)
		{
			ite->reiniciarContador();
			objetos = 3;
		}
	}
}

class Spacecraft : public Objeto
{
public:
	Spacecraft(string a, int x, int y) { existe = true; tipo = a; posX = x; posY = y; };
	static Spacecraft* getSpacecraft(string a, int x, int y);

protected:
	static Spacecraft* instance;
};

Spacecraft* Spacecraft::instance = 0;

Spacecraft* Spacecraft::getSpacecraft(string a, int x, int y)
{
	if (!instance)
		instance = new Spacecraft(a,x,y);
	return instance;
}

class Asteroid : public Objeto
{
public:
	Asteroid(string a, int x, int y) { existe = true; tipo = a; posX = x; posY = y; }
	static Asteroid* getAsteroid(string a, int x, int y);

protected:
	static Asteroid* instance;
};

Asteroid* Asteroid::instance = 0;

Asteroid* Asteroid::getAsteroid(string a, int x, int y)
{
	if (!instance)
		instance = new Asteroid(a, x, y);
	return instance;
}

class Planet : public Objeto
{
public:
	Planet(string a, int x, int y) { existe = true; tipo = a; posX = x; posY = y; }
	static Planet* getPlanet(string a, int x, int y);

protected:
	static Planet* instance;
};

Planet* Planet::instance = 0;

Planet* Planet::getPlanet(string a, int x, int y)
{
	if (!instance)
		instance = new Planet(a, x, y);
	return instance;
}

int main()
{
	ObjetoColl<Objeto*> objs;
	srand(time(NULL));
	naveChismosa* avisos = naveChismosa::getNaveChismosa();
	Objeto* nave = Spacecraft::getSpacecraft("Planet exploration ship", rand() % 5, rand() % 5);
	Objeto* asteroide = Asteroid::getAsteroid("Stony meteorite", rand() % 5, rand() % 5);
	Objeto* planeta = Planet::getPlanet("Desert planet", rand() % 5, rand() % 5);
	nave->setNoticiero(avisos);
	asteroide->setNoticiero(avisos);
	planeta->setNoticiero(avisos);
	objs.agregaObjeto(nave);
	objs.agregaObjeto(asteroide);
	objs.agregaObjeto(planeta);
	objectIterator<Objeto*>* it = objs.getIterator();
	iniciarJuego<Objeto, bool(*)(Objeto*)>(it, moverse);
	imprimeMapaColisiones();

	return 0;
}

//Correr usando: g++ -std=c++11 GalaxiaLejana.cpp -o examen
// y luego: ./examen