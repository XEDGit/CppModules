#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <cstdlib>

Base * generate(void)
{
	Base * ret;
	switch ((std::rand() % 3))
	{
		case 0:
			ret = new A();
			std::cout << "A   ";
			break;
		case 1:
			ret = new B();
			std::cout << "B   ";
			break;
		case 2:
			ret = new C();
			std::cout << "C   ";
			break;
	}
	return ret;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return;
	}
	catch(const std::exception& e)
	{}
}

int main()
{
	Base	*arr[10];
	size_t	n = 10;

	std::srand(time(0));
	std::cout << "og:" << std::endl;
	for (size_t i = 0; i < n; i++)
		arr[i] = generate();
	std::cout << std::endl << "identfy (ptr,ref):" << std::endl;
	for (size_t i = 0; i < n; i++)
	{
		identify(arr[i]);
		std::cout << ",";
		identify(*arr[i]);
		std::cout << " ";
		delete arr[i];
	}
	std::cout << std::endl;
}
