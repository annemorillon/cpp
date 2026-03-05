#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << GREY "Brain default constructor called " RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << GREY "Brain destructor called " RESET << std::endl;
}

Brain::Brain(Brain const& copy)
{
	std::cout << GREY "Brain constructor copy called " RESET << std::endl;
	*this = copy;
}

Brain	&Brain::operator=(Brain const& old)
{
	if (this != &old)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = old._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(std::string value, unsigned int index)
{
	if (index < 100)
		_ideas[index] = value;
}
std::string	Brain::getIdea(unsigned int index) const
{
	if (index > 100)
		return (NULL);
	return(_ideas[index]);
}