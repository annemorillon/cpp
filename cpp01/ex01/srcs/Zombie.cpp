#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << GREY << "Constructor Zombie " << this->_name << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << GREY << "Destructor Zombie " << this->_name << RESET << std::endl;
}

void Zombie::announce (void)
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}