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
		struct timeval startVector, endVector, startDeque, endDeque;
		pm.parsing(av);
		gettimeofday(&startVector, NULL);
		std::vector<int> tmp = pm.mergeSort(pm.getVector());
		gettimeofday(&endVector, NULL);
		pm.setAfterV(tmp);
		long secondesVector = endVector.tv_sec - startVector.tv_sec;
		long microsecondesVector = endVector.tv_usec - startVector.tv_usec;
		long timeVector = (secondesVector * 1000000) + microsecondesVector;

		gettimeofday(&startDeque, NULL);
		pm.mergeSort(pm.getDeque());
		gettimeofday(&endDeque, NULL);
		long secondesDeque = endDeque.tv_sec - startDeque.tv_sec;
		long microsecondesDeque = endDeque.tv_usec - startDeque.tv_usec;
		long timeDeque = (secondesDeque * 1000000) + microsecondesDeque;
		pm.printEnd(timeVector, timeDeque);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
		return(1);
	}
	return (0);
}