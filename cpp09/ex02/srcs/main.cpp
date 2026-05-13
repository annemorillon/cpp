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
		pm.parsing(av);
		std::vector<int> tmp = pm.mergeSort(pm.getAfterV());
		pm.setAfterV(tmp);
		pm.printEnd();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
	}
	return (0);
}