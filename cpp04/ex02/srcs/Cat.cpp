#include "../includes/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	_brain = new Brain();
	std::cout << GREY "Cat default constructor called " RESET << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << GREY "Cat destructor called " RESET << std::endl;
}

Cat::Cat(Cat const& copy): Animal(copy), _brain(NULL)
{
	std::cout << GREY "Cat constructor copy called " RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const& old)
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

void	Cat::makeSound() const
{
	std::cout << _type << ": Miaou Miaou !" << std::endl;
}

Brain*	Cat::getBrain()
{
	return (_brain);
}