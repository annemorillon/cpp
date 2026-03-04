#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << GREY "FragTrap default constructor called " RESET << std::endl;
	_name = "_FragTrap_name";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << GREY "FragTrap destructor called " RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << GREY "FragTrap constructor called " RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const& copy): ClapTrap(copy)
{
	std::cout << GREY "FragTrap constructor copy called " RESET << std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(FragTrap const& old)
{
	ClapTrap::operator=(old);
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
		std::cout << "FragTrap " << _name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}