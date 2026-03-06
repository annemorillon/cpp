#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "iostream"
# include "../includes/AMateria.hpp"

class MateriaSource
{
	public:

		virtual ~MateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

	private:

		AMateria*	
};

#endif