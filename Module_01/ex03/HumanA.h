#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <memory>
#include "Weapon.h"

class HumanA
{
	public:
		HumanA(std::string name);
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void 	attack();
		void	setWeapon(Weapon& new_weapon);
	private:
		Weapon		*weapon;
		std::string	name;
};

#endif