#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "iostream"
# include "../includes/AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:

		MateriaSource();
		~MateriaSource();

		MateriaSource(MateriaSource const& copy);

		MateriaSource	&operator=(MateriaSource const& old);

		void			learnMateria(AMateria* materia);
		AMateria*		createMateria(std::string const& type);

	private:

		AMateria*	_inventory[4];
};

#endif