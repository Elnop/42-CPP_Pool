#include "ScavTrap.h"
#include "ClapTrap.h"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("noname") {
	hp = 100; energy = 50; dmgs = 20;
	std::cout << "ScavTrap " << name << " is born! (default constructor)" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hp = 100; this->energy = 50; this->dmgs = 20;
	std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = rhs.getName();
	this->hp = rhs.getHp();
	this->energy = rhs.getEnergy();
	this->dmgs = rhs.getDmgs();
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) {
	std::cout << "ScavTrap " << name << " is born! (copy constructor)" << std::endl;
	this->name = rhs.getName();
	this->hp = rhs.getHp();
	this->energy = rhs.getEnergy();
	this->dmgs = rhs.getDmgs();
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " is destroy!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "+name+" is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
	if (this->energy == 0 || this->hp == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << dmgs << " points of damage!" << std::endl;
	this->energy -= 1;
}