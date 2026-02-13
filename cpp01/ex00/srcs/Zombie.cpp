#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
	// allocation sur la stack ?
	std::cout << GREY << "Constructor Zombie" << RESET << std::endl;
}
Zombie::~Zombie()
{
	std::cout << GREY << "Destructor Zombie" << this->name << RESET << std::endl;
}

void Zombie::announce (void)
{
	std::cout << this->name;
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}