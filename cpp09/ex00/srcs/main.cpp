#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

	if (ac != 2)
	{
		std::cerr << "Usage: ./btc [file]" << std::endl;
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
	return (0);
}