#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
}

ScavTrap::~ScavTrap()
{
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
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