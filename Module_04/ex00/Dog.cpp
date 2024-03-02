#include "Dog.h" 
#include <iostream>

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog created\n";
}

Dog::~Dog(){
	std::cout << "Dog destroy\n";
}

Dog::Dog(const Dog &rhs)
{
	type = rhs.type;
	std::cout << "Dog created (by copy)\n";
}

Dog& Dog::operator=(const Dog &rhs)
{
	type = rhs.type;
	std::cout << "Dog created (= operator)\n";
	return *this;
}

void	Dog::makeSound() {
	std::cout << "Bark !\n";
}