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

static bool	isFloat(const std::string txt)
{
	size_t i = 0;
	bool	comma = false;

	if (txt[0] == '-' || txt[0] == '+')
		i++;
	while (i < txt.length() && (std::isdigit(txt[i]) || txt[i] == '.'))
	{
		if (txt[i] == '.' && comma == true)
			return (false);
		if (txt[i] == '.')
			comma = true;
		i++;
	}
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

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		throw std::invalid_argument("bad input");
		return (false);
	}
	tmp = date.substr(0, 4);
	if (!checkYear(tmp))
	{
		throw std::invalid_argument("invalid year");
		return (false);
	}
	tmp = date.substr(5, 2);
	if (!checkMonth(tmp))
	{
		throw std::invalid_argument("invalid month");
		return (false);
	}
	tmp = date.substr(8, 2);
	if (!checkDay(tmp))
	{
		throw std::invalid_argument("invalid day");
		return (false);
	}
	return (true);
}

static bool checkValue(const std::string& tmp)
{
	std::istringstream ss(tmp);
	float	fvalue;

	ss >> fvalue;
	if (!isFloat(tmp))
	{
		throw std::invalid_argument("invalid number");
		return (false);
	}
	if (!ss.fail())
	{
		if (fvalue < 0)
		{
			throw std::out_of_range ("not a positive number");
			return (false);
		}
		else if (fvalue > 1000)
		{
			throw std::out_of_range ("too large a number");
			return (false);
		}
		return (true);
	}
	throw std::invalid_argument("invalid number");
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
	std::string file = "./data.csv";
	std::string	line;
	std::ifstream fileIn;

	fileIn.open(file.c_str());
	while (std::getline(fileIn, line))
	{
		std::string	date, comma;
		float	value;
		char *end;

		if (line.empty() || line == "date,exchange_rate")
			;
		else
		{
			int len = line.length();
			date = line.substr(0,10);
			comma = line[10];
			value = strtof((line.substr(11, len)).c_str(), &end);
			if (date.empty() || comma.empty() || (!value && value != 0))
			{
				throw std::invalid_argument("bad input");
				fileIn.close();
				return (false);
			}

			if (comma != "," || !checkDate(date))
			{
				throw;
				fileIn.close();
				return (false);
			}
			_info.insert(std::pair<std::string,float>(date,value) );
		}
	}
	fileIn.close();
	if (_info.size() == 0)
	{
		throw std::invalid_argument("file is empty");
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkLine(std::string& line)
{
	std::stringstream ss(line);
	std::string	date, value, pipe;
	float		val;
	char		*end;

	if (line.empty() || line == "date | value")
		return (true);
	try
	{
		if (!(ss >> date >> pipe >> value) || pipe != "|")
			throw std::invalid_argument("bad input");
		checkDate(date);
		checkValue(value);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << ": " << line << '\n';
		return (false);
	}
	val = strtof(value.c_str(), &end);
	findExchange(date, val);
	return (true);
}

void	BitcoinExchange::parsingFile(char *file)
{
	std::string	line;
	std::ifstream fileIn;

	fileIn.open(file);
	if (!fileIn)
		throw std::invalid_argument("open input file");
	while (std::getline(fileIn, line))
	{
		checkLine(line);
	}
}

void	BitcoinExchange::findExchange(std::string date, float value)
{
	float	result;
	float	rate = 0.0;
	std::map<std::string, float>::iterator it;

	it = _info.lower_bound(date);
	if (it == _info.begin() && date != it->first)
		std::cout << RED << "Error:" << RESET << " bad input: " << date << "\n";
	if (it == _info.end())
	{
		--it;
		rate = it->second;
	}
	else
		rate = it->second;
	result = value * rate;
	std::cout << date << " => " << value << " = " << result << "\n";
}