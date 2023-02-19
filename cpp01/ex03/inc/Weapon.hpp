#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string	type;
public:
				Weapon(void);
				Weapon(std::string ntype);
				~Weapon();
	void		setType(std::string ntype);
	std::string	getType();
};

#endif
