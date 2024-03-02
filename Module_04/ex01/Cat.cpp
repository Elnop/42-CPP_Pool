#include "Cat.h" 
#include "Brain.h"
#include <iostream>

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat created\n";
	p_brain = new Brain();
}

Cat::Cat(const Cat &rhs)
{
	type = rhs.type;
	p_brain = new Brain(*rhs.p_brain);
	std::cout << "Cat created (by copy)\n";
}

Cat& Cat::operator=(const Cat &rhs)
{
	type = rhs.type;
	p_brain = new Brain(*rhs.p_brain);
	std::cout << "Cat = operator\n";
	return *this;
}

Cat::~Cat(){
	delete p_brain;
	std::cout << "Cat destroy\n";
}

void	Cat::makeSound() {
	std::cout << "Maw !\n";
}