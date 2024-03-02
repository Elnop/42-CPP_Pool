#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap() : name("noname"), hp(10), energy(10), dmgs(5) {
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), dmgs(5) {
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) {
    this->name = rhs.getName();
	this->hp = rhs.getHp();
	this->energy = rhs.getEnergy();
	this->dmgs = rhs.getDmgs();
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = rhs.getName();
	this->hp = rhs.getHp();
	this->energy = rhs.getEnergy();
	this->dmgs = rhs.getDmgs();
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is destroy!" << std::endl;
}

std::string ClapTrap::getName() const {
	return this->name;
}

unsigned int ClapTrap::getHp() const {
	return this->hp;
}

unsigned int ClapTrap::getEnergy() const {
	return this->energy;
}

unsigned int ClapTrap::getDmgs() const {
	return this->dmgs;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energy == 0 || this->hp == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << dmgs << " points of damage!" << std::endl;
	this->energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	if (amount > this->hp)
	{
		this->hp = 0;
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
	}
	else
		this->hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
	this->hp += amount;
}
