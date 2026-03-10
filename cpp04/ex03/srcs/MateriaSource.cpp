#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int ids = 0; ids < 4; ids++)
		_inventory[ids] = NULL;
	std::cout << GREY "Character default constructor called " RESET << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}
	std::cout << GREY "Character destructor called " RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& copy)
{
	for (int ids = 0; ids < 4; ids++)
		_inventory[ids] = NULL;
	std::cout << GREY "Character constructor copy called " RESET << std::endl;
	*this = copy;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const& old)
{
	if (this != &old)
	{
		for (int ids = 0; ids < 4; ids++)
		{
			if (_inventory[ids])
				delete _inventory[ids];
			_inventory[ids] = NULL;
			if (_inventory[ids])
				_inventory[ids] = old._inventory[ids]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (int ids = 0; ids < 4; ids++)
	{
		if (!_inventory[ids])
		{
			_inventory[ids] = materia->clone();
			delete materia;
			return ;
		}
	}
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int ids = 0; ids < 4; ids++)
	{
		if (_inventory[ids] && _inventory[ids]->getType() == type)
			return (_inventory[ids]->clone());
	}
	return (NULL);
}