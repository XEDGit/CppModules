#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base * generate(void)
{
	Base * ret;
	switch ((rand() % 3))
	{
		case 0:
			ret = new A();
			break;
		case 1:
			ret = new B();
			break;
		case 2:
			ret = new C();
	}
	return ret;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{}
}

int main()
{
	Base	*arr[10];

	srand(time(0));
	std::cout << "og:" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = generate();
	}
	std::cout << "identfy:" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		identify(arr[i]);
		identify(*arr[i]);
	}
}
