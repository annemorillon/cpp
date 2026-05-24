#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe [positive integer]" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe<std::vector<int> > pmVector;
		pmVector.process(av);

		PmergeMe<std::deque<int> > pmDeque;
		pmDeque.process(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
		return(1);
	}
	return (0);
}