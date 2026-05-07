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

static bool parsingFile(std::string file)
{
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
// map = annee + value

// Parsing :
// Your program must take a file as an argument. 
// Each line in this file must use the following format: "date | value".
	// after date check if " | " otherwise INVALID
// A valid value must be either a float or a positive integer, between 0 and 1000

// ex00: map
// ex01: vector || ??
// ex02: list + set || deque + vector