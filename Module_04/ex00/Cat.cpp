#include "Cat.h" 
#include <iostream>

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat created\n";
}

Cat::~Cat(){
	std::cout << "Cat destroy\n";
}

Cat::Cat(const Cat &rhs)
{
	type = rhs.type;
	std::cout << "Cat created (by copy)\n";
}

Cat& Cat::operator=(const Cat &rhs)
{
	type = rhs.type;
	std::cout << "Cat created (= operator)\n";
	return *this;
}

void	Cat::makeSound() {
	std::cout << "Maw !\n";
}