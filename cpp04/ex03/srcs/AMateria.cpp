#include "../includes/AMateria.hpp"

AMateria()
{
	std::cout << GREY "Character default constructor called " RESET << std::endl;
}
		~AMateria();

		AMateria(std::string const& type);
		AMateria(AMateria const& copy);

		AMateria	&operator=(AMateria const& old);
		
		std::string const	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);