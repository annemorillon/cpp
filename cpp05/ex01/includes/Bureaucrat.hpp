#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"
# define PINK		"\e[0;35m"
# define DARKPINK	"\e[2;35m"
# define UNDERLINE	"\e[4;37m"

class Form;

class Bureaucrat
{
	public: 
	
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		virtual ~Bureaucrat();

		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const& copy);

		Bureaucrat	&operator=(Bureaucrat const& old);

		std::string const	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& form);

	private:

		std::string const	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif