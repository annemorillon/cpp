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
// A valid date will always be in the following format: Year-Month-Day.
	// if (year > xxxx && year < 2027)
	// if (month >= 01 && month <= 12)
	// if (day >= 01 && day <= 31) ajouter le month pour 30 ou 31
// A valid value must be either a float or a positive integer, between 0 and 1000

// ex00: map
// ex01: vector
// ex02: list + set