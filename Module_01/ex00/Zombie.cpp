#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Destroy: "+name+"\n";
}

void	Zombie::announce()
{
	std::cout << name+": BraiiiiiiinnnzzzZ...\n";
}
