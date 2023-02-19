#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
			Zombie(void);
			~Zombie();
	void	announce();
	void	newname(std::string nname);
};

Zombie* zombieHorde(int N, std::string name);

#endif