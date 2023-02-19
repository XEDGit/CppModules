#include <HumanB.hpp>

HumanB::HumanB(std::string nname)  : name(nname)
{
	weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
	else
		std::cout << name << " has nothing to attack with..." << std::endl;
}

void	HumanB::setWeapon(Weapon& nweapon)
{
	weapon = &nweapon;
}