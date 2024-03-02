#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();
		void highFivesGuys(void);
};

#endif