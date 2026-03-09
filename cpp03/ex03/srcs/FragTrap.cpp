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
