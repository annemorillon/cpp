#include "../includes/Cure.hpp"

Cure::Cure(): AMateria()
{
	_type = "cure";
	std::cout << GREY "Character constructor called " RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << GREY "Character destructor called " RESET << std::endl;
}

Cure::Cure(Cure const& copy): AMateria(copy)
{
	std::cout << GREY "Character constructor copy called " RESET << std::endl;
	*this = copy;
}

Cure	&Cure::operator=(Cure const& old)
{
	if (this != &old)
		AMateria::operator=(old);
	return (*this);
}

Cure* Cure:: clone() const
{
	return (new Cure());
}

void	use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
