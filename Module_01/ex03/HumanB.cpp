#include "HumanB.h"
#include "Weapon.h"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::HumanB(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanB::~HumanB(){}

void 	HumanB::attack()
{
	std::cout << name + " attacks with their " + weapon->type + "\n";
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	this->weapon = &new_weapon;
}
