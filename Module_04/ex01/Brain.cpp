#include "Brain.h"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain created\n";
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain created (copy constructor)\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain = operator\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destroy\n";
}