#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <FragTrap.hpp>

int main()
{
	ClapTrap gianni = ClapTrap("Gianni");
	ClapTrap luca = ClapTrap("Luca");
	ScavTrap anto = ScavTrap("Antonio");
	FragTrap mario = FragTrap("Mario");

	for (int i = 0; i < 10; i++)
	{
		gianni.attack("Luca");
		luca.takeDamage(5);
	}
	gianni.attack("Antonio");
	anto.attack("Luca");
	luca.takeDamage(20);
	luca.beRepaired(3);
	anto.guardGate();
	mario.attack("Antonio");
	anto.takeDamage(30);
	mario.attack("Antonio");
	anto.takeDamage(30);
	mario.attack("Antonio");
	anto.takeDamage(30);
	mario.attack("Antonio");
	anto.takeDamage(30);
	anto.beRepaired(20);
}
