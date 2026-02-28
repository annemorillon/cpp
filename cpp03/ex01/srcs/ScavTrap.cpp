#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_name = "random";
	_attackDamage = 100;
	_energyPoints = 50;
	_hitPoints = 20;
}

ScavTrap::~ScavTrap()
{
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_attackDamage = 100;
	_energyPoints = 50;
	_hitPoints = 20;
}

ScavTrap::ScavTrap(ScavTrap const& copy): ClapTrap(copy)
{
}

ScavTrap	&ScavTrap::operator=(ScavTrap const& old)
{
	(void) old;
	// if (this != &old)
	// {
	// 	_name = old._name;
	// 	_attackDamage = old._attackDamage;
	// 	_energyPoints = old._hitPoints;
	// 	_hitPoints = old._hitPoints;
	// }
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}