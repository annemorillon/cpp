#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << GREY "Dog default constructor called " RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << GREY "Dog destructor called " RESET << std::endl;
}

Dog::Dog(Dog const& copy): Animal(copy)
{
	std::cout << GREY "Dog constructor copy called " RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const& old)
{
	if (this != &old)
		Animal::operator=(old);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << _type << ": Ouaf Ouaf !" << std::endl;
}