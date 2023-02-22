#include <Brain.hpp>

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
	index = 0;
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
	std::cout << "Brain assignment operator called" << std::endl;
	index = old.index;
	std::copy(old.ideas, old.ideas + old.index, ideas);
	return *this;
}

void Brain::addIdea(std::string idea)
{
	if (index == 100)
	{
		std::cout << "Too many ideas for this brain" << std::endl;
		return;
	}
	ideas[index++] = idea;
}

void Brain::displayIdeas()
{
	std::cout << "Ideas:" << std::endl;
	for (int i = 0; i < index; i++)
		std::cout << "	" << ideas[i] << std::endl;
}
