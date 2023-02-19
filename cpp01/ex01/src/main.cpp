#include <Zombie.hpp>

int main()
{
	int n = 5;

	Zombie*	arr = zombieHorde(n, "Arturo");
	for (int i = 0; i < n; i++) arr[i].announce();
	delete [] arr;
	
	n = 10;

	arr = zombieHorde(n, "Maurizio");
	for (int i = 0; i < n; i++) arr[i].announce();
	delete [] arr;
	
	std::cout << "End of the program" << std::endl;
}