#include "harl.hpp"
#include <cstdlib>

int main(void)
{
	Harl harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "[ WRONG INPUT ]" << std::endl;
	harl.complain("WRONG INPUT");
	std::cout << std::endl << "[ RIEN ]" << std::endl;
	harl.complain("");
	return (0);
}