#include <Dog.hpp>

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
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
	brain = new Brain(*old.brain);
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "The dog barks" << std::endl;
}

void Dog::addIdea(std::string idea) const
{
	brain->addIdea(idea);
}

void Dog::displayIdeas() const
{
	brain->displayIdeas();
}

std::string Dog::getType() const
{
	return type;
}
