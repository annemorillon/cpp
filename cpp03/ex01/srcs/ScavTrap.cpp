#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_name = "_ScavTrap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREY << "ScavTrap default constructor called " << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREY << "ScavTrap destructor called " << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
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
		_hitPoints = old._hitPoints;
		_energyPoints = old._hitPoints;
		_attackDamage = old._attackDamage;
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
		std::cout << "ScavTrap " << _name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}