#include "ClapTrap.h"
#include "FragTrap.h"

int main(void)
{
	ClapTrap clap("CLAP");
	FragTrap frag("FRAG");
	frag.highFivesGuys();
	frag.attack("FRAG");
	clap.takeDamage(frag.getDmgs());
	frag.beRepaired(3);
	return 0;
}
