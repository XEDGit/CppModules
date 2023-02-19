#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	i->addIdea("lol");
	i->displayIdeas();
	
	const Animal k = *i;

	k.addIdea("sos");
	i->displayIdeas();
	k.displayIdeas();

	delete meta;
	delete j;
	delete i;

	return 0;
}