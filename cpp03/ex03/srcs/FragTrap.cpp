#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << GREY "FragTrap default constructor called " RESET << std::endl;
	_name = "_FRagTrap_name";
	_attackDamage = 100;
	_energyPoints = 100;
	_hitPoints = 30;
}

FragTrap::~FragTrap()
{
	std::cout << GREY "FragTrap destructor called " RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << GREY "FragTrap constructor called " RESET << std::endl;
	_attackDamage = 100;
	_energyPoints = 100;
	_hitPoints = 30;
}

FragTrap::FragTrap(FragTrap const& copy): ClapTrap(copy)
{
	std::cout << GREY "FragTrap constructor copy called " RESET << std::endl;
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

void	FragTrap::attack(std::string const& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is dead and can't attack." << std::endl;
		return;
	} 
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy left." << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}