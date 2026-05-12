#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_info = other._info;
	}
	return (*this);
}

static bool	checkYear(std::string& tmp)
{
	int	year;
	std::istringstream ss(tmp);
	ss >> year;
	if (ss.fail())
		throw ;
	if (year > 1900 && year < 2027)
		return (true);
	return (false);
}

static bool	checkMonth(std::string& tmp)
{
	int	month;
	std::istringstream ss(tmp);

	ss >> month;
	if (ss.fail())
		throw ;
	if (month >= 01 && month <= 12)
		return (true);
	return (false);
}

static bool	checkDay(std::string& tmp)
{
	int	day;
	std::istringstream ss(tmp);

	ss >> day;
	if (ss.fail())
		throw ;
	if (day >= 01 && day <= 31) //  ajouter le month pour 30 ou 31
		return (true);
	return (false);
}

static bool checkDate(std::string& date)
{
	std::string tmp;

	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	tmp = date.substr(0, 4);
	if (!checkYear(tmp))
	{
		std::cerr << "Error: invalid year: " << tmp << "\n";
		return (false);
	}
	tmp = date.substr(6, 7);
	if (!checkMonth(tmp))
	{
		std::cerr << "Error: invalid month: " << tmp << "\n";
		return (false);
	}
	tmp = date.substr(9, 10);
	if (!checkDay(tmp))
	{
		std::cerr << "Error: invalid day: " << tmp << "\n";
		return (false);
	}
	return (true);
}

static bool checkValue(std::string& tmp)
{
	std::istringstream ss(tmp);
	int		ivalue;
	float	fvalue;

	//identification type int or float ? or just conversion in float and it's okay ?
	ss >> ivalue;
	if (!ss.fail())
	{
		if (ivalue < 0)
		{
			std::cerr << "Error: not a positive number\n";
			return (false);
		}
		else if (ivalue > 1000)
		{
			std::cerr << "Error: number > 1000\n";
			return (false);
		}
		return (true);
	}
	ss >> fvalue;
	if (!ss.fail())
	{
		if (fvalue < 0)
		{
			std::cerr << "Error: not a positive number\n";
			return (false);
		}
		else if (fvalue > 1000)
		{
			std::cerr << "Error: number > 1000\n";
			return (false);
		}
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::checkLine(std::string& line)
{
	std::stringstream ss(line);
	std::string	date, value, pipe;

	if (line.empty() || line == "date | value")
		return (true);

	if (!(ss >> date >> pipe >> value))
	{
		std::cerr << "Error: bad input => " << line << "\n";
		return (false);
	}

	if (pipe != "|" || !checkDate(date) || !checkValue(value))
	{
		return (false);
	}
	findExchange(date, value);
	return (true);
}

void	BitcoinExchange::parsingFile(std::string& file)
{
	if (file.empty())
	{
		std::cerr << "Error : file is empty" << std::endl;
		return ;
	}

	std::stringstream	ss(file);
	std::string			line;

	ss.clear();
	while (std::getline(ss, line))
		checkLine(line);
}

void	BitcoinExchange::findExchange(std::string date, std::string value)
{
	std::cout << date << " => " << value << "\n";
	// trouver la date la + proche dans la map
	// recuperer la cle associe
	// afficher la date + " => " + chiffre + " = " + result;
}