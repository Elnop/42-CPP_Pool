#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal(){
	type = "notype";
}

Animal::Animal(std::string type) : type(type) {}


Animal::Animal(const Animal &lhs) {
	type = lhs.type;
}

Animal& Animal::operator=(const Animal &lhs) {
	type = lhs.type;
	return *this;
}

Animal::~Animal() {}

void	Animal::makeSound() const{
	std::cout << "gakjdghaljskngRGKERGEWW\n";
}