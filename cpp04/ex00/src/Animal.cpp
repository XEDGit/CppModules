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
	std::cout << "Animal assignement operator called" << std::endl;
	type = old.type;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void	Animal::makeSound(void) const
{
	std::cout << "The animal makes an extremely generic noise" << std::endl;
}