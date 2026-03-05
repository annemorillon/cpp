#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class WrongAnimal
{
	public:

		WrongAnimal();
		virtual ~WrongAnimal();

		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const& copy);

		WrongAnimal		&operator=(WrongAnimal const& old);

		virtual void		makeSound() const;
		virtual std::string	getType() const;

	protected:

		std::string	_type;
};

#endif