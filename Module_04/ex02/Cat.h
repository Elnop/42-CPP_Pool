#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
	private:
		Brain*	p_brain;
	public:
		Cat();
		Cat(const Cat& rhs);
		Cat& operator=(const Cat &rhs);
		~Cat();
		void	makeSound();
};

#endif