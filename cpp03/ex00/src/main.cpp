#include <ClapTrap.hpp>

int main()
{
	ClapTrap gianni = ClapTrap("Gianni");
	ClapTrap anto = ClapTrap("Antonio");

	gianni.attack("Antonio");
	anto.takeDamage(5);
	anto.attack("Gianni");
	gianni.takeDamage(5);
	gianni.beRepaired(3);
	anto.attack("Gianni");
	gianni.takeDamage(5);
	gianni.attack("Antonio");
	anto.takeDamage(5);
	anto.attack("Gianni");
}
