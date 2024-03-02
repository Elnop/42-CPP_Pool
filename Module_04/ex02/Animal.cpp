#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal(){
	std::cout << "Animal created (default constructor)\n";
	type = "notype";
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal created\n";
}


Animal::Animal(const Animal &lhs) {
	std::cout << "Animal created (copy constructor)\n";
	type = lhs.type;
}

Animal& Animal::operator=(const Animal &lhs) {
	std::cout << "Animal = operator\n";
	type = lhs.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroy\n";
}

void	Animal::makeSound() const{
	std::cout << "gakjdghaljskngRGKERGEWW\n";
}