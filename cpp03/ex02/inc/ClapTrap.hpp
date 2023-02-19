#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int			health;
		int			energy;
		int			damage;

	public:
					ClapTrap(std::string name);
					~ClapTrap();
					ClapTrap(const ClapTrap &old);
		ClapTrap& 	operator=(const ClapTrap &old);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
