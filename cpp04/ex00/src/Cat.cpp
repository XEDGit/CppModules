#include <Cat.hpp>

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& old)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = old;
}

Cat&	Cat::operator=(const Cat& old)
{
	std::cout << "Cat assignment operator called" << std::endl;
	type = old.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "The cat meows" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}
