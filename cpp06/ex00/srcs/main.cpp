#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Usage: ./convert [value]" << std::endl;
	ScalarConverter::convert(av[1]);
}