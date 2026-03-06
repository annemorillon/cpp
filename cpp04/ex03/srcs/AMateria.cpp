#include "../includes/AMateria.hpp"

AMateria::AMateria(): _type("Default")
{
	std::cout << GREY "Character default constructor called " RESET << std::endl;
}
AMateria::~AMateria()
{
	std::cout << GREY "Character destructor called " RESET << std::endl;
}

AMateria::AMateria(std::string const& type): _type(type)
{
	std::cout << GREY "Character constructor called " RESET << std::endl;
}

AMateria::AMateria(AMateria const& copy)
{
	std::cout << GREY "Character constructor copy called " RESET << std::endl;
	*this = copy;
}

AMateria	&AMateria::operator=(AMateria const& old)
{
	if (this != &old)
	{
		_type = old._type;
	}
	return (*this);
}

std::string const	AMateria::getType() const
{
	return (_type);
}

void		AMateria::use(ICharacter& target)
{
	std::cout << _type << ": use is not defined" << std::endl;
}