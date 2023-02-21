#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main()
{
	const Dog* j = new Dog();
	const Cat* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();

	i->addIdea("lol");
	i->displayIdeas();
	
	const Cat k = *i;

	k.addIdea("sos");
	i->displayIdeas();
	k.displayIdeas();

	delete j;
	delete i;

	return 0;
}