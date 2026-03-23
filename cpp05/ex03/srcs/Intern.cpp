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

AForm*	Intern::makeForm(std::string name, std::string target)
{
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
	std::string tab[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "SchrubberyCreationForm"};

	int i = 0;
	while (i < 3)
	{
		if (tab[i] == name)
			break;
		i++;
	}

	switch (i)
	{
		case 0:
		{
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm());
		}
		case 1:
		{
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm());
		}
		case 2:
		{
			std::cout << "Intern creates " << name << std::endl;
			return (new SchrubberyCreationForm());
		}
		default:
		{
			std::cout << "Error: " << name << " doesn't exist !" << std::endl;
			return (NULL);
		}
	}
}
