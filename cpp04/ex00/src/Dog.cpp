#include <Dog.hpp>

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& old)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = old;
}

Dog&	Dog::operator=(const Dog& old)
{
	std::cout << "Dog assignment operator called" << std::endl;
	type = old.type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "The dog barks" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}
