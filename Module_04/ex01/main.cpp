#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
int main()
{
	Dog 	Nasus;
	Nasus.makeSound();
	Dog dupNasus = Dog(Nasus);
	dupNasus.makeSound();

	Cat 	Yuumi;
	Yuumi.makeSound();
	
	Animal	Zac;
	Zac.makeSound();
}