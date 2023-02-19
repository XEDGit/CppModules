#include <Zombie.hpp>

Zombie::Zombie(std::string newname)
{
	name = newname;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

