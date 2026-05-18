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
		_before = other._before;
		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);
}

void	PmergeMe::_parsing(char **av)
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
				{
					_before.push_back(atoi(tmp.c_str()));
					_deque.push_back(atoi(tmp.c_str()));
				}
				space = j;
			}
			j++;
		}
		if (space == 0)
		{
			if (atoi(av[i]) > 0) // gerer si c'est un double
			{
				_before.push_back(atoi(av[i]));
				_deque.push_back(atoi(av[i]));
			}
		}
		i++;
	}
	_vector = _before;
}

long PmergeMe::_calculateTime(struct timeval start, struct timeval end) const
{
	return ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
}

void	PmergeMe::_merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right)
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

void	PmergeMe::_mergeSort(std::vector<int>& arr)
{
	std::vector<int> left;
	std::vector<int> right;
	
	if (arr.size() <= 1)
		return ;

	int middle = arr.size() / 2;

	for (int i = 0; i < middle; i++)
		left.push_back(arr[i]);

	for (int i = middle; (long unsigned int) i < arr.size(); i++)
		right.push_back(arr[i]);

	_mergeSort(left);
	_mergeSort(right);
	_merge(arr, left, right);
}

void	PmergeMe::_merge(std::deque<int>& arr, std::deque<int>& left, std::deque<int>& right)
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

void	PmergeMe::_mergeSort(std::deque<int>& arr)
{
	std::deque<int> left;
	std::deque<int> right;
	
	if (arr.size() <= 1)
		return ;

	int middle = arr.size() / 2;

	for (int i = 0; i < middle; i++)
		left.push_back(arr[i]);

	for (int i = middle; (long unsigned int) i < arr.size(); i++)
		right.push_back(arr[i]);

	_mergeSort(left);
	_mergeSort(right);
	_merge(arr, left, right);

}

void	PmergeMe::_printEnd(struct timeval startVector, struct timeval endVector, struct timeval startDeque, struct timeval endDeque)
{
	std::cout << "Before: ";
	print(_before);
	std::cout << "After: ";
	print(_vector);

	long timeVector = _calculateTime(startVector, endVector);
	long timeDeque = _calculateTime(startDeque, endDeque);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::[vector] : " << timeVector << " us" << "\n";
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::[deque] : " << timeDeque << " us" << "\n";
}

void	PmergeMe::process(char **av)
{
	struct timeval startVector, endVector, startDeque, endDeque;

	_parsing(av);

	gettimeofday(&startVector, NULL);
	_mergeSort(_vector);
	gettimeofday(&endVector, NULL);

	gettimeofday(&startDeque, NULL);
	_mergeSort(_deque);
	gettimeofday(&endDeque, NULL);

	_printEnd(startVector, endVector, startDeque, endDeque);
}