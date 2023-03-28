#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main()
{
	const Animal *arr[20];

	for (int i = 0; i < 20; i++)
	{
		if (rand() % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (int i = 0; i < 20; i++)
		delete arr[i];

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