#include "ScalarConverter.hpp"
#include "sstream"

void ScalarConverter::convert(std::string param)
{
	char c;
	int i;
	float f;
	double d;

	std::stringstream ss(param);

	ss >> c;
	ss >> i;
	ss >> f;
	ss >> d;

	if (c)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (f)
		std::cout << "f: " << f << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (d)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const& other){*this = other;}
ScalarConverter ScalarConverter::operator=(ScalarConverter const& other)
{
	(void) other;
	return (*this);
}