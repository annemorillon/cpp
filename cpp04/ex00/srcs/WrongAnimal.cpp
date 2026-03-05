#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << GREY "WrongAnimal default constructor called " RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREY "WrongAnimal destructor called " RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << GREY "WrongAnimal constructor called " RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy)
{
	std::cout << GREY "WrongAnimal constructor copy called " RESET << std::endl;
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const& old)
{
	if (this != &old)
	{
		_type = old._type;
	}
	return (*this);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "The WrongAnimal isn't defined." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}