#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& rhs);
		Cat& operator=(const Cat &rhs);
		~Cat();
		void	makeSound();
};

#endif