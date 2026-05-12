#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::string	file;
	BitcoinExchange btc;

	if (ac != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return (1);
	}
	if (!btc.openAndCopyFile(av[1], file))
		return (1);
	if (!btc.setInfo()) //=> parsing ?
	{
		std::cerr << "Error: _info doesn't fill \n";
	}
	btc.parsingFile(file);
}

// test :
// file is empty

// map = cle + value
// map = date + value=6

// ex00: map
// ex01: stack
// ex02: deque + vector