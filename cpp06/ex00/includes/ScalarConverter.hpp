#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "iostream"
# include <sstream>
# include <cmath>
# include <limits>

enum TYPE {
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
};

# define INT_MIN std::numeric_limits<int>::min()
# define INT_MAX std::numeric_limits<int>::max()
# define FLOAT_MIN std::numeric_limits<float>::min()
# define FLOAT_MAX std::numeric_limits<float>::max()
# define DOUBLE_MIN std::numeric_limits<double>::min()
# define DOUBLE_MAX std::numeric_limits<double>::max()

class ScalarConverter
{
	public:

		static void convert(std::string value);

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		ScalarConverter operator=(ScalarConverter const& other);

};

#endif