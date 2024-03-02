#include <iostream>
#include "Character.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"
#include "Ice.h"
#include "Cure.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->unequip(0); // test unequip no delete materia
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}