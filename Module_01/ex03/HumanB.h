#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <memory>
#include "Weapon.h"

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon& weapon);
		~HumanB();
		void 	attack();
		void	setWeapon(Weapon& new_weapon);
	private:
		Weapon		*weapon;
		std::string	name;
};

#endif