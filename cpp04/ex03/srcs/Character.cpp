#include "../includes/Character.hpp"

Character::Character(): _name("Character")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << GREY "Character default constructor called " RESET << std::endl;
}

Character::~Character()
{
	std::cout << GREY "Character destructor called " RESET << std::endl;
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << GREY "Character constructor called " RESET << std::endl;
}

Character::Character(Character const& copy)
{
	std::cout << GREY "Character constructor copy called " RESET << std::endl;
	*this = copy;
}

Character	&Character::operator=(Character const& old)
{
	if (this != &old)
	{
		_name = old._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i]; // est-ce qu'il faut delete ??
		}
		for (int i = 0; i < 4; i++)
			_inventory[i] = new AMateria(*old._inventory[i]);
		// copy deep for materias
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (!_inventory[idx])
		{
			_inventory[idx] = m;
			std::cout << _name << " equip " << _inventory[idx]->getType() << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int ids)
{
	std::cout << _name << " leaves on the floor " << _inventory[ids]->getType() << std::endl;
	_inventory[ids] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	_inventory[idx]->use(target);
}