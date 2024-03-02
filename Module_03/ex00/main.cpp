#include "ClapTrap.h"

int main(void)
{
	ClapTrap clap("Clap1");
	ClapTrap clap2;
	ClapTrap clap3 = clap;
	clap.attack("Clap2");
	clap2.takeDamage(5);
	clap.beRepaired(3);
	return 0;
}
