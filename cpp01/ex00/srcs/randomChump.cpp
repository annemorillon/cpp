#include "../includes/Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie* Zombie = newZombie(name);

	Zombie.announce();
}