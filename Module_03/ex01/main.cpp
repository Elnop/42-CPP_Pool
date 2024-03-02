#include "ClapTrap.h"
#include "ScavTrap.h"

int main(void)
{
	ScavTrap clap("Clap1");
	ScavTrap clap2;
	clap.guardGate();
	clap.attack("Clap2");
	clap2.takeDamage(5);
	clap2.beRepaired(3);
	return 0;
}
