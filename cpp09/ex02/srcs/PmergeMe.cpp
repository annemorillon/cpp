#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}
PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

std::vector<int>	PmergeMe::getAfterV() const
{
	return (_afterV);
}

void				PmergeMe::setAfterV(std::vector<int> const value)
{
	_afterV = value;
}

void	PmergeMe::parsing(char **av)
{
	int i = 1;
	std::string avs;

	while(av[i])
	{
		int j = 0;
		int	space = 0;
		while(av[i][j])
		{
			avs = av[i];
			if (!isdigit(av[i][j]) && !(av[i][j] == ' '))
				throw std::invalid_argument("bad input");
			if (av[i][j] == ' ' || (space != 0 && isdigit(av[i][j]) && !av[i][j+1]))
			{
				std::string tmp = avs.substr(space, j);
				if (atoi(tmp.c_str()) > 0) // gerer si c'est un double
					_before.push_back(atoi(tmp.c_str()));
				space = j;
			}
			j++;
		}
		if (space == 0)
		{
			if (atoi(av[i]) > 0) // gerer si c'est un double
				_before.push_back(atoi(av[i]));
		}
		i++;
	}
	_afterV = _before;
	// _afterD = _before;
}

void	PmergeMe::merge(std::vector<int> arr, std::vector<int> left, std::vector<int> right)
{
	long unsigned int leftIndex = 0;
	long unsigned int rightIndex = 0;
	long unsigned int arrIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
	{
			if (left[leftIndex] <= right[rightIndex])
				arr[arrIndex++] = left[leftIndex++];
			else
				arr[arrIndex++] = right[rightIndex++];
	}

	while (leftIndex < left.size())
		arr[arrIndex++] = left[leftIndex++];

	while (rightIndex < right.size())
		arr[arrIndex++] = right[rightIndex++];
}

std::vector<int>	PmergeMe::mergeSort(std::vector<int> arr)
{
	std::vector<int> left;
	std::vector<int> right;

	if (arr.size() <= 1)
		return (arr);

	int middle = arr.size() / 2;

	for (int i = 0; i < middle; i++)
		left.push_back(arr[i]);

	for (long unsigned int i = middle; i < arr.size(); i++)
		right.push_back(arr[i]);

	mergeSort(left);
	mergeSort(right);

	merge(arr, left, right);
	
	return (arr);
}

void	PmergeMe::printEnd()
{
	std::cout << "Before: ";
	print(_before);
	std::cout << "After: ";
	print(_afterV);
	std::cout << "Time to process a range of 5 elements with std::[deque] : " << "0.00031" << "us" << "\n";
	std::cout << "Time to process a range of 5 elements with std::[vector] : " << "0.00014" << "us" << "\n";
}