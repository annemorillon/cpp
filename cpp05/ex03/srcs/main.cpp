#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "SchrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << PINK "\n=== Invalid form ===" RESET << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	{
		std::cout << PINK "\n=== Empty form ===" RESET << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("", "Bender");
	}
	{
		std::cout << PINK "\n=== Empty target ===" RESET << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "");
	}
	{
		std::cout << PINK "\n=== Valid PresidentialPardonForm ===" RESET << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "home");
	}
	{
		std::cout << PINK "\n=== Valid RobotomyRequestForm ===" RESET << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "home");
	}
	{
		std::cout << PINK "\n=== Valid SchrubberyCreationForm ===" RESET << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("SchrubberyCreationForm", "home");
		Bureaucrat George("George", 5);
	}
}