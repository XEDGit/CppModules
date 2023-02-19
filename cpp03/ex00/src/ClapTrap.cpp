#include <ClapTrap.hpp>

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << "Claptrap " << name << " created" << std::endl;
	health = 10;
	energy = 10;
	damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &old)
{
	*this = old;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energy == 0 || health == 0)
	{
		std::cout << "Claptrap " << name << " has no " << (energy? "health" : "energy") << " left" << std::endl;
		return;
	}
	std::cout << "Claptrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
	energy --;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap " << name << " takes " << amount << " points of damage!" << std::endl;
	health -= amount;
	if (health < 0) health = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy == 0 || health == 0)
	{
		std::cout << "Claptrap " << name << " has no " << (energy? "health" : "energy") << " left" << std::endl;
		return;
	}
	std::cout << "Claptrap " << name << " repairs by " << amount << " points of health!" << std::endl;	
	health += amount;
	energy --;
}

ClapTrap	&ClapTrap::operator =(const ClapTrap &old)
{
	name = old.name;
	health = old.health;
	energy = old.energy;
	damage = old.damage;
	return *this;
}
