#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << GREY "DiamondTrap default constructor called " RESET << std::endl;
	_name = "_DiamondTrap_name";
	FragTrap::_attackDamage = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_hitPoints = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << GREY "DiamondTrap destructor called " RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << GREY "DiamondTrap constructor called " RESET << std::endl;
	_name = name;
	FragTrap::_attackDamage = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_hitPoints = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy): ScavTrap(copy), FragTrap(copy)
{
	std::cout << GREY "DiamondTrap constructor copy called " RESET << std::endl;
	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const& old)
{
	if (this != &old)
	{
		_name = old._name;
		FragTrap::_attackDamage = old.FragTrap::_attackDamage;
		ScavTrap::_energyPoints = old.ScavTrap::_hitPoints;
		FragTrap::_hitPoints = old.FragTrap::_hitPoints;
	}
	return (*this);
}

// void	DiamondTrap::ScavTrap::attack(std::string const& target)
// {
// 	if (_hitPoints == 0)
// 	{
// 		std::cout << "FragTrap " << _name << " is dead and can't attack." << std::endl;
// 		return;
// 	} 
// 	if (_energyPoints == 0)
// 	{
// 		std::cout << "FragTrap " << _name << " has no energy left." << std::endl;
// 		return;
// 	}
// 	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
// 	_energyPoints--;
// }

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name : " << _name << std::endl;
	std::cout << "ClaTrap Name : " << FragTrap::ClapTrap::_name << std::endl;
}
