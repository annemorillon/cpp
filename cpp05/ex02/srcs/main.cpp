#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "SchrubberyCreationForm.hpp"
int main(void)
{
	std::cout << PINK "\n=== Invalid execution ===" RESET << std::endl;
	try
	{
		Bureaucrat George("George", 5);
		Bureaucrat Vincent("Vincent", 50);
		PresidentialPardonForm form3("Zadi");
		George.signForm(form3);
		Vincent.executeForm(form3);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PINK "\n=== Valid execution ===" RESET << std::endl;
	try
	{
		Bureaucrat George("George", 5);
		PresidentialPardonForm form3("Zadi");
		George.signForm(form3);
		George.executeForm(form3);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PINK "\n=== Invalid execution ===" RESET << std::endl;
	try
	{
		Bureaucrat George("George", 5);
		Bureaucrat Vincent("Vincent", 50);
		RobotomyRequestForm form3("Rob");
		George.signForm(form3);
		Vincent.executeForm(form3);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PINK "\n=== Valid execution ===" RESET << std::endl;
	try
	{
		Bureaucrat George("George", 5);
		RobotomyRequestForm form3("Rob");
		George.signForm(form3);
		George.executeForm(form3);
		RobotomyRequestForm form4("Rob");
		George.signForm(form4);
		George.executeForm(form4);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PINK "\n=== Invalid execution ===" RESET << std::endl;
	try
	{
		Bureaucrat George("George", 5);
		Bureaucrat Vincent("Vincent", 50);
		SchrubberyCreationForm form3("Rob");
		George.signForm(form3);
		Vincent.executeForm(form3);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PINK "\n=== Valid execution ===" RESET << std::endl;
	try
	{
		Bureaucrat George("George", 5);
		SchrubberyCreationForm form3("Rob");
		George.signForm(form3);
		George.executeForm(form3);
		SchrubberyCreationForm form4("Rob");
		George.signForm(form4);
		George.executeForm(form4);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}