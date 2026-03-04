#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("_ClapTrap_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREY "Default constructor called " RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << GREY "Destructor called " RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREY "Constructor called " RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
	std::cout << GREY "Constructor copy called " RESET << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const& old)
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

void	ClapTrap::attack(std::string const& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
		return;
	} 
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (_hitPoints < amount || _hitPoints - amount == 0)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and dies!" << std::endl;
		return;
	}
	_hitPoints -= amount;
	std:: cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't repaire." << std::endl;
		return;
	} 
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to repaire." << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repaired " << amount << " points of health !" << std::endl;
}

void	ClapTrap::setHitPoint(unsigned int value)
{
	_hitPoints = value;
}

void	ClapTrap::setEnergyPoint(unsigned int value)
{
	_energyPoints = value;
}

void	ClapTrap::setAttackDamage(unsigned int value)
{
	_attackDamage = value;
}

unsigned int	ClapTrap::getHitPoint(void)
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoint(void)
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return (_attackDamage);
}