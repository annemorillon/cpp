#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	std::cout << GREY << "Constructor HumanB" << RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << GREY << "Destructor HumanB" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->_name;
	if (!_weapon)
		std::cout << " don't have a weapon" << std::endl;
	else
	{
		std::cout << " attacks with their ";
		std::cout << this->_weapon->getType() << std::endl;
	}
}