#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << GREY "WrongCat default constructor called " RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << GREY "WrongCat destructor called " RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const& copy): WrongAnimal(copy)
{
	std::cout << GREY "WrongCat constructor copy called " RESET << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const& old)
{
	WrongAnimal::operator=(old);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << _type << ": Beeeeeee !" << std::endl;
}