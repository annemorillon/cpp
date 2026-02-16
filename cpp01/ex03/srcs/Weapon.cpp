#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string value)
{
	this->_type = value;
	std::cout << GREY << "Constructor Weapon" << RESET << std::endl;
}
Weapon::~Weapon()
{
	std::cout << GREY << "Destructor Weapon" << RESET << std::endl;
}

std::string	Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string value)
{
	this->_type = value;
}
