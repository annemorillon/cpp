#include "../includes/Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << GREY "Animal default constructor called " RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << GREY "Animal destructor called " RESET << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << GREY "Animal constructor called " RESET << std::endl;
}

Animal::Animal(Animal const& copy)
{
	std::cout << GREY "Animal constructor copy called " RESET << std::endl;
	*this = copy;
}

Animal	&Animal::operator=(Animal const& old)
{
	if (this != &old)
	{
		_type = old._type;
	}
	return (*this);
}

std::string	Animal::getType() const
{
	return (_type);
}

Brain*	Animal::getBrain()
{
	return (NULL);
}