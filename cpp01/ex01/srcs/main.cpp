#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie* zombies = zombieHorde(5, "zombie");	
	delete[] zombies;
}