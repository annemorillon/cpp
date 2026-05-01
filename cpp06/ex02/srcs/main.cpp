#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "cstdlib"
#include "time.h"

Base * generate(void)
{
	int nb = rand() % 3;
	switch (nb)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (new A());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object C" << std::endl;
	else
		std::cout << "Unknow type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Object A" << std::endl;
		return ;
	}	catch (...) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Object B" << std::endl;
		return ;
	}	catch (...) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Object C" << std::endl;
		return ;
	} catch (...) {}
	std::cout << "Unknow type" << std::endl;
}

int main(void) {
	srand( time( NULL ) );
	std::cout << "═══════════════════════════════════════" << std::endl;
	std::cout << "             Identify type             " << std::endl;
	std::cout << "═══════════════════════════════════════" << std::endl;

	for (int i = 1; i <= 5; i++) {
		std::cout << "\n--- Round " << i << " ---" << std::endl;

		Base *obj = generate();
		identify(obj);
		identify(*obj);

		delete obj;
	}

	std::cout << "\n═══════════════════════════════════════" << std::endl;
	std::cout << "        Tests with forced types        " << std::endl;
	std::cout << "═══════════════════════════════════════" << std::endl;

	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	std::cout << "\n[Force A]" << std::endl;
	identify(a);
	identify(*a);

	std::cout << "\n[Force B]" << std::endl;
	identify(b);
	identify(*b);

	std::cout << "\n[Force C]" << std::endl;
	identify(c);
	identify(*c);

	std::cout << "\n[Force NULL]" << std::endl;
	identify(NULL);

	delete a;
	delete b;
	delete c;

	std::cout << "\n═══════════════════════════════════════" << std::endl;
	std::cout << "              Done!                    " << std::endl;
	std::cout << "═══════════════════════════════════════" << std::endl;

	return (0);
}