#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;
	
	const Cat* cat = new Cat();

	cat->addIdea("lol");
	cat->displayIdeas();
	
	const Animal* k = new Cat(*cat);

	k->addIdea("sos");
	cat->displayIdeas();
	k->displayIdeas();

	delete k;
	delete cat;

	return 0;
}