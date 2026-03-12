#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"
# include "../includes/ICharacter.hpp"
# include "../includes/IMateriaSource.hpp"

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"
# define PINK		"\e[0;35m"
# define DARKPINK	"\e[2;35m"
# define UNDERLINE	"\e[4;37m"

class Bureaucrat
{
	public: 
	
		Bureaucrat();
		virtual ~Bureaucrat();

		Bureaucrat(std::string const& name);
		Bureaucrat(Bureaucrat const& copy);

		Bureaucrat	&operator=(Bureaucrat const& old);

		std::string const	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

	protected:
		std::string const	_name;
		int					_grade;
};

#endif