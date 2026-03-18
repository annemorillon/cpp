#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat Etienne("Etienne", 125);
		Form form("contrat", 120, 130);
		Etienne.signForm(form);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Julia("Julia", 125);
		Form form2("contrat", 10, 10);
		Julia.signForm(form2);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat George("George", 125);
		Form form3("contrat", 160, 160);
		George.signForm(form3);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
}