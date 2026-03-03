#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_name = "_ScavTrap_name";
	_attackDamage = 100;
	_energyPoints = 50;
	_hitPoints = 20;
	std::cout << GREY << "ScavTrap default constructor called " << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREY << "ScavTrap destructor called " << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_attackDamage = 100;
	_energyPoints = 50;
	_hitPoints = 20;
	std::cout << GREY << "ScavTrap constructor called " << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& copy): ClapTrap(copy)
{
	std::cout << GREY "ScavTrap constructor copy called " RESET << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const& old)
{
	if (this != &old)
	{
		_name = old._name;
		_attackDamage = old._attackDamage;
		_energyPoints = old._hitPoints;
		_hitPoints = old._hitPoints;
	}
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(std::string const& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and can't attack." << std::endl;
		return;
	} 
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}