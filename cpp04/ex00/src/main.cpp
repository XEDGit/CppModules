#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

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

	delete meta;
	delete j;
	delete i;

	WrongAnimal* wrong = new WrongAnimal();
	WrongAnimal* wrongcat = new WrongCat();
	
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	
	wrong->makeSound();
	wrongcat->makeSound();

	delete wrong;
	delete wrongcat;
	return 0;
}