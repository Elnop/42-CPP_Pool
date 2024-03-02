#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
	private:
		std::string		name;
		unsigned int	hp;
		unsigned int	energy;
		unsigned int	dmgs;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &rhs);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& rhs);
		std::string getName() const;
		unsigned int getHp() const;
		unsigned int getEnergy() const;
		unsigned int getDmgs() const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif