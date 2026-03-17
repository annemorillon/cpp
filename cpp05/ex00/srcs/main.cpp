#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Etienne("Etienne", 300);
	std::cout << Etienne;
	Etienne.incrementGrade();
	std::cout << Etienne;
	Bureaucrat Virginie("Virginie", -5);
	std::cout << Virginie;
	Bureaucrat David("David", 125);
	std::cout << David;
	David.decrementGrade();
	Bureaucrat George("George", 1);
	std::cout << George;
	George.incrementGrade();
	Bureaucrat Julia("Julia", 100);
	Julia.incrementGrade();
	Julia.incrementGrade();
	Julia.incrementGrade();
	Julia.incrementGrade();
	std::cout << Julia;
}