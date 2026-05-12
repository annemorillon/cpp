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

int main(int ac, char **av)
{
	std::string	file;
	BitcoinExchange B;

	if (ac != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return (1);
	}
	if (!openAndCopyFile(av[1], file))
		return (1);
	// fill _info with data.csv => parsing ?
	B.parsingFile(file);
}

// test :
// file is empty

// map = cle + value
// map = date + value=6

// ex00: map
// ex01: stack
// ex02: deque + vector