#ifndef CURE_HPP
# define CURE_HPP

# include "iostream"
# include "../includes/AMateria.hpp"

class Cure: public AMateria
{
	public: 
	
		Cure();
		~Cure();

		Cure(Cure const& copy);

		Cure	&operator=(Cure const& old);

		virtual Cure*	clone() const;
		virtual void	use(ICharacter& target);

	private:

};

#endif