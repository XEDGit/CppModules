#include <HumanA.hpp>

HumanA::HumanA(std::string nname, Weapon& nweapon) : name(nname), weapon(nweapon)
{
}

HumanA::~HumanA()
{
}


void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}