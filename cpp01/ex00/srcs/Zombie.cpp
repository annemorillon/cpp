#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << GREY << "Constructor Zombie " << this->_name << RESET << std::endl;
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