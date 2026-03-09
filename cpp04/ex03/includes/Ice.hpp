#ifndef Ice_HPP
# define Ice_HPP

# include "iostream"
# include "../includes/AMateria.hpp"

class Ice: public AMateria
{
	public: 
	
		Ice();
		~Ice();

		Ice(Ice const& copy);

		Ice	&operator=(Ice const& old);

		virtual Ice*	clone() const;
		virtual void	use(ICharacter& target);

	private:

};

#endif