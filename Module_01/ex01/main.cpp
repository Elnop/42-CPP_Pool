#include "Zombie.hpp"
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "./zombie <number of zombies> <zombies name>";
		return (2);
	}
	Zombie *zombieList = zombieHorde(std::atoi(av[1]), av[2]);
	for (int i = 0; i < std::atoi(av[1]); i++)
	{
		zombieList[i].announce();
	}
	delete[] zombieList;
}
