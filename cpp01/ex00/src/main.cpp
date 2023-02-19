#include <Zombie.hpp>

int main()
{
	Zombie*	heapZombie = newZombie("Heap zombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stack zombie");

	std::cout << "End of the program" << std::endl;
}