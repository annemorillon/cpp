#include "../includes/BitcoinExchange.hpp"

static bool	isAllDigit(const std::string txt)
{
	size_t i = 0;

	while (i < txt.length() && std::isdigit(txt[i]))
		i++;
	if (i < txt.length())
		return (false);
	return (true);	
}
static bool	checkYear(const std::string& tmp)
{
	int	year;
	std::istringstream ss(tmp);
	
	ss >> year;
	if (ss.fail())
		throw ;
	if (!isAllDigit(tmp))
		return (false);
	if (year > 1900 && year < 2027)
		return (true);
	return (false);
}

static bool	checkMonth(const std::string& tmp)
{
	int	month;
	std::istringstream ss(tmp);

	ss >> month;
	if (ss.fail())
		throw ;
	if (!isAllDigit(tmp))
		return (false);
	if (month >= 01 && month <= 12)
		return (true);
	return (false);
}

static bool	checkDay(const std::string& tmp)
{
	int	day;
	std::istringstream ss(tmp);

	ss >> day;
	if (ss.fail())
		throw ;
	if (!isAllDigit(tmp))
		return (false);
	if (day >= 01 && day <= 31) //  ajouter le month pour 30 ou 31
		return (true);
	return (false);
}

static bool checkDate(const std::string& date)
{
	std::string tmp;

	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	tmp = date.substr(0, 4);
	if (!checkYear(tmp))
	{
		std::cerr << RED "Error: invalid year: " RESET << tmp << "\n";
		return (false);
	}
	tmp = date.substr(5, 2);
	if (!checkMonth(tmp))
	{
		std::cerr << RED "Error: invalid month: " RESET << tmp << "\n";
		return (false);
	}
	tmp = date.substr(8, 2);
	if (!checkDay(tmp))
	{
		std::cerr << RED "Error: invalid day: " RESET << tmp << "\n";
		return (false);
	}
	return (true);
}

static bool checkValue(const std::string& tmp)
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
			std::cerr << RED "Error: not a positive number\n" RESET;
			return (false);
		}
		else if (ivalue > 1000)
		{
			std::cerr << RED "Error: number > 1000\n" RESET;
			return (false);
		}
		return (true);
	}
	ss >> fvalue;
	if (!ss.fail())
	{
		if (fvalue < 0)
		{
			std::cerr << RED "Error: not a positive number\n" RESET;
			return (false);
		}
		else if (fvalue > 1000)
		{
			std::cerr << RED "Error: number > 1000\n" RESET;
			return (false);
		}
		return (true);
	}
	return (false);
}

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

bool	BitcoinExchange::setInfo()
{
	std::string file;
	std::string address = "./data.csv";
	if (!openAndCopyFile(address.c_str(), file))
		return (false);
	if (file.empty())
	{
		std::cerr << RED "Error : file is empty" RESET << std::endl;
		return (false);
	}

	std::stringstream	ss(file);
	std::string			line;

	while (std::getline(ss, line))
	{
		std::string	date, value, comma;

		if (line.empty() || line == "date,exchange_rate")
			;
		else
		{
			int len = line.length();
			date = line.substr(0,10);
			comma = line[10];
			value = line.substr(11, len);
			if (date.empty() || comma.empty() || value.empty())
			{
				std::cerr << RED "Error: bad input => " RESET << line << "\n";
				return (false);
			}

			if (comma != "," || !checkDate(date))
			{
				std::cout << date << " => " << value << "\n";
				return (false);
			}
			_info.insert (std::pair<std::string,std::string>(date,value) );
		}
	}

	// std::map<std::string,std::string>::iterator it = ++_info.begin();

	// while (it!=_info.end())
	// {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	++it;
	// }
	return (true);
}


bool	BitcoinExchange::openAndCopyFile(const char *file, std::string& txt)
{
	std::string	line;

	std::ifstream fileIn;

	fileIn.open(file);
	if (!fileIn)
	{
		std::cerr << RED "Error: open fileIn" RESET << std::endl;
		return (false);
	}
	while (1)
	{
		txt += line;
		if (!getline(fileIn, line))
			break;
		else
			txt += '\n';
	}
	fileIn.close();
	return (true);
}

bool	BitcoinExchange::checkLine(std::string& line)
{
	std::stringstream ss(line);
	std::string	date, value, pipe;

	if (line.empty() || line == "date | value")
		return (true);

	if (!(ss >> date >> pipe >> value))
	{
		std::cerr << RED "Error: bad input => " RESET << line << "\n";
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
		std::cerr << RED "Error : file is empty" RESET << std::endl;
		return ;
	}

	std::stringstream	ss(file);
	std::string			line;

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