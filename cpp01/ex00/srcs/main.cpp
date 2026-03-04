#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie	zombie1("42");
	Zombie	*zombie2;

	zombie2 = newZombie("43");
	zombie1.announce();
	zombie2->announce();
	randomChump("44");
	delete zombie2;

	return (0);
}