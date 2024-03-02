#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &rhs);
		Animal& operator=(const Animal &rhs);
		~Animal();
		void	makeSound() const;
};

#endif
