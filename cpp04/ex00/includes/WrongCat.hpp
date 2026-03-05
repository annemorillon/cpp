#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "iostream"
# include "WrongAnimal.hpp"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class WrongCat: public WrongAnimal
{
	public:

		WrongCat();
		virtual ~WrongCat();

		WrongCat(WrongCat const& copy);

		WrongCat		&operator=(WrongCat const& old);

		virtual void	makeSound() const;

};

#endif