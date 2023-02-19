#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int main()
{
	ClapTrap gianni = ClapTrap("Gianni");
	ClapTrap luca = ClapTrap("Luca");
	ScavTrap anto = ScavTrap("Antonio");

	for (int i = 0; i < 10; i++)
	{
		gianni.attack("Luca");
		luca.takeDamage(5);
	}
	gianni.attack("Anotnio");
	anto.attack("Luca");
	luca.takeDamage(20);
	luca.beRepaired(3);
	anto.guardGate();
}
