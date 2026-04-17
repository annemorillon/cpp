#include "ScalarConverter.hpp"
#include <sstream>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const& other){*this = other;}
ScalarConverter ScalarConverter::operator=(ScalarConverter const& other)
{
	(void) other;
	return (*this);
}


static int	detectType(std::string param)
{
	if (param.length() == 1 && !isdigit(param[0]))
		return (CHAR);
	if (!(param[0] == '+' || param[0] == '-' || isdigit(param[0])))
			return (OTHER);
	for (long unsigned int i = 1; i < param.length(); i++)
	{
		if (param[i] == '+' || param[i] == '-')
			;
		else if (isspace(param[i]))
			return (OTHER);
		else if (param[i] == '.')
		{
			i++;
			std::cout << param[i] << std::endl;
			if (!param[i] || !isdigit(param[i]))
				return (OTHER);
			i++;
			std::cout << param[i] << std::endl;
			if (i == param.length())
				return (DOUBLE);
			if (param[i] == 'f' && i + 1 == param.length())
				return (FLOAT);
			return (OTHER);
		}
	}
	return (INT);
}

static void convertChar(char c)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void convertInt(double i)
{
	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void convertDouble(double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
	    std::cout << "char: impossible" << std::endl;
	    std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (d < 32 || d > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d<< std::endl;
}

static void convertFloat(float f)
{
	if (std::isnan(f) || std::isinf(f))
	{
	    std::cout << "char: impossible" << std::endl;
	    std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (f < 32 || f > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << static_cast<double>(f)<< std::endl;
}

void ScalarConverter::convert(std::string param)
{
	int type = detectType(param);
	std::stringstream ss(param);

	switch (type)
	{
		case CHAR:
		{
			char c = param[0];
			convertChar(c);
			break;
		}
		case INT:
		{
			double i(0);
			ss >> i;
			if (ss.fail())
			{
				std::cout << "conversion failed int\n";
				return ;
			}
			convertInt(i);
			break;
		}
		case DOUBLE:
		{
			double d;
			ss >> d;
			if (ss.fail())
			{
				std::cout << "conversion failed double\n";
				return ;
			}
			convertDouble(d);
			break;
		}
		case FLOAT:
		{
			float f;
			ss >> f;
			if (ss.fail())
			{
				std::cout << "conversion failed float\n";
				return ;
			}
			convertFloat(f);
			break;
		}
		default:
		{
			std::cout << "conversion failed default\n";
			break;
		}
	}
	
    //  caster explicitement vers les 3 autres types
    //  afficher (ou "impossible" / "Non displayable")

	// nan, +inf, -inf = double
	// nanf, +inff, -inff = float
}
