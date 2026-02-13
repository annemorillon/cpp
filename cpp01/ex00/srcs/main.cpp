#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie	zombie1("42");
	Zombie	*zombie2;

	zombie2 = newZombie("43");
	zombie1.announce();
	zombie2->announce();
	delete zombie2;
	randomChump("44");
}