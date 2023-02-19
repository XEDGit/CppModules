#include <Zombie.hpp>

void randomChump(std::string name)
{
	Zombie ran = Zombie(name);
	ran.announce();
}