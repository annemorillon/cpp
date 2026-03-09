#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "iostream"
# include "../includes/ICharacter.hpp"
# include "../includes/IMateriaSource.hpp"

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"
# define PINK		"\e[0;35m"
# define DARKPINK	"\e[2;35m"
# define UNDERLINE	"\e[4;37m"

class AMateria
{
	public: 
	
		AMateria();
		virtual ~AMateria();

		AMateria(std::string const& type);
		AMateria(AMateria const& copy);

		AMateria	&operator=(AMateria const& old);
		
		std::string const	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	_type;
};

#endif