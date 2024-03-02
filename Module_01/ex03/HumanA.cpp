#include "HumanA.h"
#include "Weapon.h"

HumanA::HumanA(std::string name)
{
	this->name = name;
}

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(){}

void 	HumanA::attack()
{
	std::cout << name + " attacks with their " + weapon->type + "\n";
}

void	HumanA::setWeapon(Weapon& new_weapon)
{
	this->weapon = &new_weapon;
}