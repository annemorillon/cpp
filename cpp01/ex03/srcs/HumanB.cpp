#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	std::cout << GREY << "Constructor HumanB" << RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << GREY << "Destructor HumanB" << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}