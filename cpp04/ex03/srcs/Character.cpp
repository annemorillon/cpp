#include "../includes/Character.hpp"

Character::Character(): _name("Character")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << GREY "Character default constructor called " RESET << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}
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
	for (int i = 0; i < 4; i++)
			_inventory[i] = NULL;
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
				delete _inventory[i];
			_inventory[i] = NULL;
			if (old._inventory[i])
				_inventory[i] = old._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* materia)
{
	if (!materia)
		return;
	for (int ids = 0; ids < 4; ids++)
	{
		if (materia == _inventory[ids])
			return ;
		if (!_inventory[ids] && materia)
		{
			_inventory[ids] = materia;
			return ;
		}
	}
}

void	Character::unequip(int ids)
{
	if (ids >= 0 && ids < 4 && _inventory[ids])
		_inventory[ids] = NULL;
}

void	Character::use(int ids, ICharacter& target)
{
	if (ids >= 0 && ids < 4 && _inventory[ids])
		_inventory[ids]->use(target);
}

AMateria*	Character::getMateria(int ids) const
{
	if (ids >= 0 && ids < 4)
		return (_inventory[ids]);
	return (NULL);
}