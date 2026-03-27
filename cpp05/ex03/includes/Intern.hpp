#ifndef INTERN_HPP
# define INTERN_HPP

class AForm;
# include "iostream"

class Intern
{
	public:

		Intern();
		~Intern();
		Intern(Intern const& other);
		Intern& operator=(Intern const& other);

		AForm*	makeForm(std::string name, std::string target);

		AForm*	presidentialForm(const std::string& target);
		AForm*	robotomyForm(const std::string& target);
		AForm*	schrubberyForm(const std::string& target);

		class NotFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

#endif