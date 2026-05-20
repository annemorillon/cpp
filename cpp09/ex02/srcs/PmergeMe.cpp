#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
	_before.clear();
	_vector.clear();
	_deque.clear();
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}
PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_before.clear();
		_vector.clear();
		_deque.clear();
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
				if (atoi(tmp.c_str())) // a modifier
				{
					_before.push_back(atoi(tmp.c_str()));
					_deque.push_back(atoi(tmp.c_str()));
				}
				else
					throw std::invalid_argument("bad input");
				space = j;
			}
			j++;
		}
		if (space == 0)
		{
			if (atoi(av[i]) > 0) // a modifier
			{
				_before.push_back(atoi(av[i]));
				_deque.push_back(atoi(av[i]));
			}
			else
				throw std::invalid_argument("bad input");
		}
		i++;
	}
	_vector = _before;
}

long PmergeMe::_calculateTime(struct timeval start, struct timeval end) const
{
	return ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
}

static std::vector<int>	sequenceJacobsthal(int n)
{
	std::vector<int> result;
	int tmp = 0;

	result.push_back(0);
	if (n == 0)
		return (result);
	result.push_back(1);
	for (int i = 2; tmp <= n; i++)
	{
		tmp = result[i - 1] + 2 * result[i - 2];
		if (tmp < n)
			result.push_back(tmp);
	}
	std::vector<int>::iterator it = result.begin();
	it++;
	result.erase(it);
	for(int i = 0; i < n; i++)
	{
		std::vector<int>::iterator it = find(result.begin(), result.end(), i);
		if (it != result.end())
			;
		else
			result.push_back(i);
	}
	return (result);
}

void	PmergeMe::_sort(std::vector<int>& arr)
{
	std::vector<int> main;
	std::vector<int> pending;
	std::vector<int> non_participating;
	
	if (arr.size() <= 1)
		return ;

	if (arr.size() % 2 != 0)
		non_participating.push_back(arr.back());

	long unsigned int i = 0;
	while (i + 1 < arr.size())
	{
		int a = arr[i];
		i++;
		int b = -1;
		if (arr[i])
			b = arr[i];
		if (a && b != -1)
		{
			main.push_back(std::max(a, b));
			pending.push_back(std::min(a, b));
		}
		i++;
	}

	_sort(main);
	
	std::cout << "main: ";
	print(main);
	std::cout << "pending: ";
	print(pending);
	std::cout << "\n";

	std::vector<int> jacobsthal = sequenceJacobsthal((int) arr.size());

	std::cout << "jacobsthal: ";
	print(jacobsthal);

	for (long unsigned int i = 0; i < jacobsthal.size() && (long unsigned int)jacobsthal[i] < pending.size(); i++)
	{
		int value = pending[jacobsthal[i]];
		std::vector<int>::iterator it = lower_bound(main.begin(), main.end(), value);
		main.insert(it, value);
		// int j = jacobsthal[i];
		// while (i >= 1 && j > 1 && j != jacobsthal[i - 1])
		// {
		// 	j--;
		// 	int value = pending[j];
		// 	std::vector<int>::iterator it = find(pending.begin(), pending.end(), value);
		// 	if (it == pending.end())
		// 		;
		// 	else
		// 	{
		// 		std::vector<int>::iterator it = lower_bound(main.begin(), main.end(), value);
		// 		main.insert(it, value);
		// 	}
		// }
	}


	// std::cout << "non participating: ";
	// print(non_participating);

	for (long unsigned int i = 0; i < non_participating.size(); i++)
	{
		std::vector<int>::iterator it = lower_bound(main.begin(), main.end(), non_participating[i]);
		main.insert(it, non_participating[i]);
	}

	std::cout << "after: ";
	print(main);
	std::cout << "\n";
	arr = main;
}

// void	PmergeMe::_mergeSort(std::deque<int>& arr)
// {
// 	std::deque<int> left;
// 	std::deque<int> right;
	
// 	if (arr.size() <= 1)
// 		return ;

// 	int middle = arr.size() / 2;

// 	for (int i = 0; i < middle; i++)
// 		left.push_back(arr[i]);

// 	for (int i = middle; (long unsigned int) i < arr.size(); i++)
// 		right.push_back(arr[i]);

// 	_mergeSort(left);
// 	_mergeSort(right);
// 	_merge(arr, left, right);

// }

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
	_sort(_vector);
	gettimeofday(&endVector, NULL);

	// gettimeofday(&startDeque, NULL);
	// // _mergeSort(_deque);
	// gettimeofday(&endDeque, NULL);

	_printEnd(startVector, endVector, startDeque, endDeque);
}