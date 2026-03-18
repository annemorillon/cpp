#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat Etienne("Etienne", 300);
		std::cout << Etienne;
		Etienne.incrementGrade();
		std::cout << Etienne;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Virginie("Virginie", -5);
		std::cout << Virginie;
		Bureaucrat David("David", 125);
		std::cout << David;
		David.decrementGrade();
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat George("George", 1);
		George.incrementGrade();
		std::cout << George;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Julia("Julia", 100);
		std::cout << Julia;
		Julia.incrementGrade();
		Julia.incrementGrade();
		Julia.incrementGrade();
		Julia.incrementGrade();
		std::cout << Julia;
		Julia.decrementGrade();
		std::cout << Julia;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
}