#ifndef CAT_HPP
# define CAT_HPP

# include "iostream"
# include "Animal.hpp"
# include "Brain.hpp"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Cat: public Animal
{
	public:

		Cat();
		~Cat();

		Cat(Cat const& copy);

		Cat		&operator=(Cat const& old);

		void	makeSound() const;
		Brain*	getBrain();

	private:

		Brain*	_brain;

};

#endif