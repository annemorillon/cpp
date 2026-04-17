#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "iostream"

enum TYPE {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class ScalarConverter
{
	public:

		static void convert(std::string param);

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		ScalarConverter operator=(ScalarConverter const& other);

};

#endif