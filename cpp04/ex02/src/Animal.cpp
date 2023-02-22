#include <Animal.hpp>

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	type = "very generic";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& old)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = old;
}

Animal&	Animal::operator=(const Animal& old)
{
	std::cout << "Animal assignment operator called" << std::endl;
	type = old.type;
	return *this;
}
