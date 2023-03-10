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

std::string Animal::getType() const
{
	return type;
}

void	Animal::makeSound(void) const
{
	std::cout << "The animal makes an extremely generic noise" << std::endl;
}

void Animal::addIdea(std::string idea) const
{
	std::cout << "The animal is trying to think about " << idea << " but he doesn't have a brain"  << std::endl;
}

void Animal::displayIdeas() const
{
	std::cout << "Nothing to see here, there's no brain" << std::endl;
}
