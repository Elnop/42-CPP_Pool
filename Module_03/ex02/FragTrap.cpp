#include "FragTrap.h"
#include "ClapTrap.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	hp = 100; energy = 100; dmgs = 30;
	std::cout << "FragTrap " << name << " is born! (default constructor)" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hp = 100; this->energy = 100; this->dmgs = 30;
	std::cout << "FragTrap " << name << " is born!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->name = rhs.getName();
	this->hp = rhs.getHp();
	this->energy = rhs.getEnergy();
	this->dmgs = rhs.getDmgs();
	return *this;
}

FragTrap::FragTrap(const FragTrap& rhs) {
	std::cout << "FragTrap " << name << " is born! (copy constructor)" << std::endl;
	this->name = rhs.getName();
	this->hp = rhs.getHp();
	this->energy = rhs.getEnergy();
	this->dmgs = rhs.getDmgs();
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " is destroy!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "a positive high fives request\n";
}