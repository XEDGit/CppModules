#include <Cat.hpp>

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
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
	brain = new Brain(*old.brain);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "The cat meows" << std::endl;
}

void Cat::addIdea(std::string idea) const
{
	brain->addIdea(idea);
}

void Cat::displayIdeas() const
{
	brain->displayIdeas();
}

std::string Cat::getType() const
{
	return type;
}
