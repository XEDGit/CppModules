#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = "wrongly generic";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& old)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = old;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& old)
{
	std::cout << "WrongAnimal assignement operator called" << std::endl;
	type = old.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "The animal makes the wrong noise" << std::endl;
}