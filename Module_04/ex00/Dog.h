#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& rhs);
		Dog& operator=(const Dog &rhs);
		~Dog();
		void	makeSound();
};

#endif