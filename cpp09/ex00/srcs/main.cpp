#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

	if (ac != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return (1);
	}
	try
	{
		btc.setInfo();
		btc.parsingFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
	}
}

// test :
// file is empty

// map = cle + value
// map = date + value=6

// ex00: map
// ex01: stack
// ex02: deque + vector