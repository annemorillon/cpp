#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "iostream"
# include "Brain.hpp"

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"
# define PINK		"\e[0;35m"
# define DARKPINK	"\e[2;35m"
# define UNDERLINE	"\e[4;37m"

class Animal
{
	public:

		Animal();
		virtual ~Animal();

		Animal(std::string type);
		Animal(Animal const& copy);

		Animal		&operator=(Animal const& old);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
		virtual Brain*		getBrain();

	protected:

		std::string	_type;
};

#endif