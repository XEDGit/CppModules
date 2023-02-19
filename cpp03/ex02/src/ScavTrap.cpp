#include <ScavTrap.hpp>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Scavtrap " << name << " created" << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap " << name << " destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energy == 0 || health == 0)
	{
		std::cout << "Scavtrap " << name << " has no " << (energy? "health" : "energy") << " left" << std::endl;
		return;
	}
	std::cout << "Scavtrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
	energy --;
}
