#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	_name = name;
	std::cout << GREY << "Constructor HumanA" << RESET << std::endl;
}

HumanA::~HumanA()
{
	std::cout << GREY << "Destructor HumanA" << RESET << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}