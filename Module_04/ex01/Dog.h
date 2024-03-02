#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
	private:
		Brain*	p_brain;
	public:
		Dog();
		Dog(const Dog& rhs);
		Dog& operator=(const Dog &rhs);
		~Dog();
		void	makeSound();
};

#endif