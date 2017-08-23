#include <iostream>

using namespace std;

class FactoryProduct
{
public:
	template<class Prod>
	Prod* factoryMethod()
	{
		return new Prod;
	}
};

class ProductA : public FactoryProduct
{
public:
	void operation()
	{
		cout << "Estoy en el producto A" << endl;
	}
};

int main()
{
	FactoryProduct* p = new FactoryProduct;
	ProductA* a = p->factoryMethod<ProductA>();
	a->operation();
	int ab;
	cin >> ab;
}