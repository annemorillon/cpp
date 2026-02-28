#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	_name = "random";
	_attackDamage = 100;
	_energyPoints = 100;
	_hitPoints = 30;
}

FragTrap::~FragTrap()
{
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_attackDamage = 100;
	_energyPoints = 100;
	_hitPoints = 30;
}

FragTrap::FragTrap(FragTrap const& copy): ClapTrap(copy)
{
	*this = copy;
}

FragTrap	&FragTrap::operator=(FragTrap const& old)
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

void	FragTrap::highFivesGuys()
{
	std::cout << "High-fives" << std::endl;
}