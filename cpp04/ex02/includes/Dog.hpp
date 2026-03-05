#ifndef DOG_HPP
# define DOG_HPP

# include "iostream"
# include "Animal.hpp"
# include "Brain.hpp"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Dog: public Animal
{
	public:

		Dog();
		virtual ~Dog();

		Dog(Dog const& copy);

		Dog		&operator=(Dog const& old);

		virtual void	makeSound() const;
		virtual Brain*			getBrain();

	private:

		Brain*	_brain;
};

#endif