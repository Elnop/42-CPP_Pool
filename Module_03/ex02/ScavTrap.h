#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap& operator=(const ScavTrap& rhs);
		ScavTrap(const ScavTrap &rhs);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};

#endif