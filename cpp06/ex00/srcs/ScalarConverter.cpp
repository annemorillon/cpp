#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const& other){*this = other;}
ScalarConverter ScalarConverter::operator=(ScalarConverter const& other)
{
	(void) other;
	return (*this);
}

static int	detectType(std::string value)
{
	if (value == "nan" || value == "+inf" || value == "-inf" \
		|| value == "nanf" || value == "+inff" || value == "-inff")
		return (SPECIAL);
	if (value.length() == 1 && !isdigit(value[0]))
		return (CHAR);
	if (!(value[0] == '+' || value[0] == '-' || isdigit(value[0])))
			return (INVALID);
	for (long unsigned int i = 1; i < value.length(); i++)
	{
		if (value[i] == '+' || value[i] == '-')
			;
		else if (isspace(value[i]))
			return (INVALID);
		else if (value[i] == '.')
		{
			i++;
			if (!value[i] || !isdigit(value[i]))
				return (INVALID);
			i++;
			if (i == value.length())
				return (DOUBLE);
			if (value[i] == 'f' && i + 1 == value.length())
				return (FLOAT);
			return (INVALID);
		}
	}
	return (INT);
}

void	convertSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static void convertChar(char c)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (c > INT_MAX || c < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(c) << std::endl;
	if (c > FLOAT_MAX || c < FLOAT_MIN)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(c) << std::endl;
	if (c > DOUBLE_MAX || c < DOUBLE_MIN)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void convertInt(int i)
{
	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (i > FLOAT_MAX || i < FLOAT_MIN)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(i) << std::endl;
	if (i > DOUBLE_MAX || i < DOUBLE_MIN)
		std::cout << "double: impossible" << std::endl;
	else
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
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	if (d > FLOAT_MAX || d < FLOAT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
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
		if (f > INT_MAX || f < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << std::endl;
	if (f > DOUBLE_MAX || f < DOUBLE_MIN)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convert(std::string value)
{
	int type = detectType(value);
	std::stringstream ss(value);

	switch (type)
	{
		case SPECIAL:
			convertSpecial(value);
			break;
		case CHAR:
		{
			char c = value[0];
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
			std::cerr << "Usage: ./convert [value] (char, int, float or double)" << std::endl;
			break;
	}
}
