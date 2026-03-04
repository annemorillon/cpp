#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << GREY "DiamondTrap default constructor called " RESET << std::endl;
	_name = "_DiamondTrap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << GREY "DiamondTrap destructor called " RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << GREY "DiamondTrap constructor called " RESET << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << GREY "DiamondTrap constructor copy called " RESET << std::endl;
	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const& old)
{
	if (this != &old)
	{
		_name = old._name;
		_hitPoints = old._hitPoints;
		_energyPoints = old._hitPoints;
		_attackDamage = old._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name : " << _name << std::endl;
	std::cout << "ClaTrap Name : " << ClapTrap::_name << std::endl;
}
