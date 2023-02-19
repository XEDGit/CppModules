#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <Weapon.hpp>

class HumanB
{
private:
	Weapon*		weapon;
	std::string	name;
public:
			HumanB(std::string nname);
			~HumanB();
	void	attack();
	void	setWeapon(Weapon& nweapon);
};

#endif
