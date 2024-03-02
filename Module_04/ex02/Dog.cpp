#include "Dog.h" 
#include "Brain.h"
#include <iostream>

Dog::Dog() : Animal("Dog"){
	p_brain = new Brain();
	std::cout << "Dog created\n";
}

Dog::~Dog(){
	delete p_brain;
	std::cout << "Dog destroy\n";
}

Dog::Dog(const Dog &rhs)
{
	type = rhs.type;
	p_brain = new Brain(*rhs.p_brain);
	std::cout << "Dog created (by copy)\n";
}

Dog& Dog::operator=(const Dog &rhs)
{
	type = rhs.type;
	p_brain = new Brain(*rhs.p_brain);
	std::cout << "Dog = operator\n";
	return *this;
}

void	Dog::makeSound() {
	std::cout << "Bark !\n";
}