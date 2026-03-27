#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "SchrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(Intern const& other)
{
	*this = other;
}

Intern& Intern::operator=(Intern const& other)
{
	(void) other;
	return (*this);
}

AForm* Intern::presidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::robotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::schrubberyForm(const std::string& target)
{
	return (new SchrubberyCreationForm(target));
}


AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string tab[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "SchrubberyCreationForm"};
	AForm* (Intern::*ptrForm[3]) (const std::string&) = {&Intern::schrubberyForm, &Intern::robotomyForm, &Intern::presidentialForm};
	int i = 0;

	if (name.empty())
	{
		std::cout << "Error: name of the form doesn't exist !" << std::endl;
		return (NULL);
	}
	if (target.empty())
	{
		std::cout << "Error: target doesn't exist !" << std::endl;
		return (NULL);
	}
	// try
	// {
		while (i < 3)
		{
			if (tab[i] == name)
			{
				std::cout << "Intern creates " << name << std::endl;
				return (this->*ptrForm[i])(target);
			}
			i++;
		}
		throw NotFormException();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
}

const char* Intern::NotFormException::what() const throw()
{
	return("Error: the form does'nt exist !");
}