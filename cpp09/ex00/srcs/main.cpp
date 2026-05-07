#include "../includes/BitcoinExchange.hpp"

static bool	openAndCopyFile(char *file, std::string& txt)
{
	std::string	line;

	std::ifstream fileIn;

	fileIn.open(file);
	if (!fileIn)
	{
		std::cerr << "Error: open fileIn" << std::endl;
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

static bool	checkYear(std::string& tmp)
{
	int	year;
	std::istringstream ss(tmp);
	ss >> year;
	if (ss.fail())
		throw ;
	if (year > 1900 && year < 2027)
		return (false);
	return (true);
}

static bool	checkMonth(std::string& tmp)
{
	int	month;
	std::istringstream ss(tmp);

	ss >> month;
	if (ss.fail())
		throw ;
	if (month >= 01 && month <= 12)
		return (false);
	return (true);
}

static bool	checkMonth(std::string& tmp)
{
	int	month;
	std::istringstream ss(tmp);

	ss >> month;
	if (ss.fail())
		throw ;
	if (month >= 01 && month <= 12)
		return (false);
	return (true);
}

static bool	checkDay(std::string& tmp)
{
	int	day;
	std::istringstream ss(tmp);

	ss >> day;
	if (ss.fail())
		throw ;
	if (day >= 01 && day <= 31) //  ajouter le month pour 30 ou 31
		return (false);
	return (true);
}

static bool checkDate(std::string& date)
{
	std::string tmp;

	if (date.length() != 10)
		return (false);
	if (date[5] != '|' || date[8] != '|')
		return (false);
	tmp = date.substr(0, 4);
	if (!checkYear(tmp))
		return (false);
	tmp = date.substr(6, 7);
	if (!checkMonth(tmp))
		return (false);
	tmp = date.substr(9, 10);
	if (!checkDay(tmp))
		return (false);
}

static bool checkValue(std::string& tmp)
{
	std::istringstream ss(tmp);
	int		ivalue;
	float	fvalue;

	//identification type int or float ? or just conversion in float and it's okay ?
	ss >> ivalue;
	if (ivalue >= 0 && ivalue <= 1000)
		return (true);
	ss >> fvalue;
	if (fvalue >= 0 && fvalue <= 1000)
		return (true);
	return (false);
}

static bool checkLine(std::string& line)
{
	std::stringstream ss(line);
	std::string	date, value, pipe;

	if (std::count(line.begin(), line.end(), ' ') != 2) {
		return (false);
	}

	if (!(ss >> date >> pipe >> value))
		return (false);

	if (pipe != "|" || !checkDate(date) || !checkValue(value))
		return (false);

	// add in map ??
}

static bool parsingFile(std::string file)
{
	std::stringstream	ss(file);
	std::string			line;

	while (std::getline(ss, line))
	{
		if (!checkLine(line))
			return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	std::string	file;

	if (ac != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return (1);
	}
	if (!openAndCopyFile(av[1], file))
		return (1);
	if (!parsingFile(file))
		return (1);
		// parsing file
	// trouver la date la + proche dans la map
	// recuperer la cle associe
	// afficher la date + " => " + chiffre + " = " + result
}

// test :
// file is empty

// map = cle + value
// map = date + value

// ex00: map
// ex01: vector || ??
// ex02: list + set || deque + vector