#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << GREY "Cat default constructor called " RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << GREY "Cat destructor called " RESET << std::endl;
}

Cat::Cat(Cat const& copy): Animal(copy)
{
	std::cout << GREY "Cat constructor copy called " RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const& old)
{
	Animal::operator=(old);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << _type << ": Miaou Miaou !" << std::endl;
}