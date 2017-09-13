#include <iostream>

//typedef int(*func)(int);

using namespace std;

template <class SIMI>
class IntIterator;

template<class SIMI>
class IntCollection
{
protected:
	SIMI* array;
	int size;
	int cont;
public:
	friend class IntIterator<SIMI>;

	IntCollection()
	{
		size = 10;
		array = new SIMI[size];
		cont = 0;
	}
	
	void addElement(SIMI value)
	{
		if (cont <= size)
		{
			array[cont++] = value;
			return;
		}
		cout << "ya no hay espacio para agregar elementos!" << endl;
	}

	IntIterator<SIMI>* getIterator();
	
	SIMI at(int pos)
	{
		return array[pos];
	}
};

template<class SIMI>
class IntIterator
{
protected:
	IntCollection<SIMI> coll;
	int cont = 0;
public:
	IntIterator(const IntCollection<SIMI>& coll) : coll(coll) {}

	bool hasNext()
	{
		if (cont < coll.cont)
		{
			return true;
		}
		return false;
	}
	
	SIMI next()
	{
		return coll.at(cont++);
	}
};

template <class SIMI>
IntIterator<SIMI> * IntCollection<SIMI>::getIterator()
{
	return new IntIterator<SIMI>(*this);
}

template<class SIMI, class Function>
void find_if(IntIterator<SIMI>* ite, Function func)
{
	int n;
	while (ite->hasNext())
	{
		SIMI n = ite->next();
		if (func(n))
		{
			cout << n << endl;
		}
	}	
}

bool buscar(int n)
{
	if (n < 10)
		return true;
	else
		return false;
}

//bool buscar(char c)
//{
//	if (c == 'b')
//		return true;
//	else
//		return false;
//}

int main()
{
	IntCollection<int> i;
	i.addElement(1);
	i.addElement(4);
	i.addElement(2);
	i.addElement(3);
	IntIterator<int>* it = i.getIterator();
	find_if<int, bool(*)(int)>(it, buscar);

	delete it;

	int b;
	cin >> b;
}