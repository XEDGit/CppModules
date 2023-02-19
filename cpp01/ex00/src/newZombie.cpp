#include <Zombie.hpp>

Zombie* newZombie(std::string name)
{
	Zombie*	ret = new Zombie(name);
	ret->announce();
	return (ret);
}