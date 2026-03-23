#ifndef AFORM_HPP
# define AFORM_HPP

# include "iostream"
# include "fstream"
class Bureaucrat;

class AForm
{
	public:

		AForm();
		virtual ~AForm();

		AForm(const std::string name, const int gradetoexecute, const int gradetosign);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat& bureaucrat);
		
		virtual void		execute(Bureaucrat const& executor) const = 0;

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

		class FormNotSignedException: public std::exception
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

std::ostream& operator<<(std::ostream& os, AForm& AForm);

#endif