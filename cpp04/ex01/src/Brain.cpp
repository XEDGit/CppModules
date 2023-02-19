#include <Brain.hpp>

Brain::Brain(void)
{
	std::cout << "Brain void constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& old)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = old;
}

Brain&	Brain::operator=(const Brain& old)
{
	std::cout << "Brain assignement operator called" << std::endl;
	std::copy(old.ideas, old.ideas + old.ideas->length(), ideas);
	return *this;
}

void Brain::addIdea(std::string idea)
{
	ideas[index++] = idea;
}

void Brain::displayIdeas()
{
	std::cout << "Ideas:" << std::endl;
	for (int i = 0; i < index; i++)
		std::cout << "	" << ideas[i] << std::endl;
}
