#include "../includes/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	_brain = new Brain();
	std::cout << GREY "Dog default constructor called " RESET << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << GREY "Dog destructor called " RESET << std::endl;
}

Dog::Dog(Dog const& copy): Animal(copy), _brain(NULL)
{
	std::cout << GREY "Dog constructor copy called " RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const& old)
{
	if (this != &old)
	{
		Animal::operator=(old);
		if (_brain)
			delete _brain;
		_brain = new Brain(*old._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << _type << ": Ouaf Ouaf !" << std::endl;
}

Brain*	Dog::getBrain()
{
	return (_brain);
}
