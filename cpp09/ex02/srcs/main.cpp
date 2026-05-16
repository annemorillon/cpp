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
		struct timeval startVector, endVector;
		pm.parsing(av);
		gettimeofday(&startVector, NULL);
		std::vector<int> tmp = pm.mergeSort(pm.getAfterV());
		gettimeofday(&endVector, NULL);
		pm.setAfterV(tmp);
		long secondesVector = endVector.tv_sec - startVector.tv_sec;
		long microsecondesVector = endVector.tv_usec - startVector.tv_usec;
		long timeVector = (secondesVector * 1000000) + microsecondesVector;
		pm.printEnd(timeVector, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
		return(1);
	}
	return (0);
}