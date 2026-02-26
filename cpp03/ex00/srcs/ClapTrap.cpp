#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
    _name = copy._name;
    _attackDamage = copy._attackDamage;
    _energyPoints = copy._hitPoints;
    _hitPoints = copy._hitPoints;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const& old)
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

void ClapTrap::attack(std::string const& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    } 
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy left." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    if (_hitPoints < _attackDamage)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    } 
    _hitPoints -= _attackDamage;
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    } 
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    } 
    _attackDamage = amount;   
    std:: cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    } 
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy left." << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " repaired!" << std::endl;
}

void    ClapTrap::setHitPoint(unsigned int value)
{
    _hitPoints = value;
}

void    ClapTrap::setEnergyPoint(unsigned int value)
{
    _energyPoints = value;
}

void    ClapTrap::setAttackDamage(unsigned int value)
{
    _attackDamage = value;
}

unsigned int     ClapTrap::getHitPoint(void)
{
    return (_hitPoints);
}

unsigned int     ClapTrap::getEnergyPoint(void)
{
    return (_energyPoints);
}

unsigned int     ClapTrap::getAttackDamage(void)
{
    return (_attackDamage);
}