#include <FragTrap.hpp>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Fragtrap " << name << " created" << std::endl;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Fragtrap " << name << " destroyed" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "Fragtrap " << name << " gives an high five!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (energy == 0 || health == 0)
	{
		std::cout << "Fragtrap " << name << " has no " << (energy? "health" : "energy") << " left" << std::endl;
		return;
	}
	std::cout << "Fragtrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
	energy --;
}
