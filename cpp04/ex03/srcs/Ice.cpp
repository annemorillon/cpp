#include "../includes/Ice.hpp"

Ice::Ice(): AMateria()
{
	_type = "ice";
	std::cout << GREY "Character constructor called " RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << GREY "Character destructor called " RESET << std::endl;
}

Ice::Ice(Ice const& copy): AMateria(copy)
{
	std::cout << GREY "Character constructor copy called " RESET << std::endl;
	*this = copy;
}

Ice	&Ice::operator=(Ice const& old)
{
	if (this != &old)
		AMateria::operator=(old);
	return (*this);
}

Ice* Ice:: clone() const
{
	return (new Ice());
}

void	use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}