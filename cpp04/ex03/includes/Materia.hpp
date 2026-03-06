#ifndef MATERIA_HPP
# define MATERIA_HPP

# include "iostream"
# include "../includes/AMateria.hpp"
# include "../includes/IMateriaSource.hpp"

class AMateria: public IMateriaSource, public AMateria
{
	public: 
	
		
	protected:
		std::string	_type;
};

#endif