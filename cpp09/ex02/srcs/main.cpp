#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pm;

	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe [positive integer]" << std::endl;
		return (1);
	}
	try
	{
		pm.process(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
		return(1);
	}
	return (0);
}