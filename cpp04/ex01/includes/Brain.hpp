#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "iostream"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Brain
{
	public:

		Brain();
		virtual ~Brain();

		Brain(Brain const& copy);

		Brain		&operator=(Brain const& old);

		virtual void		setIdea(std::string value, unsigned int index);
		virtual std::string	getIdea(unsigned int index) const;

	protected:

		std::string	_ideas[100];
};

#endif