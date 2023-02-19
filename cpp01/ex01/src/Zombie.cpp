#include <Zombie.hpp>

Zombie::Zombie(void)
{
	name.clear();
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed" << std::endl;
}

void	Zombie::newname(std::string nname)
{
	name = nname;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}