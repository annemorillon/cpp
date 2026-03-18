#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	public:

		Form();
		~Form();

		Form(const std::string name, const int gradetoexecute, const int gradetosign);
		Form(const Form& other);
		Form &operator=(const Form& other);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat& bureaucrat);
		

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

	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif