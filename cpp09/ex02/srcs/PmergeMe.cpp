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
	std::vector<int> jacob;
	std::vector<int> result;
	jacob.push_back(0);
	if (n == 0)
		return (result);
	jacob.push_back(1);
	
	while (jacob.back() < n)
	{
		int next = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
		if (next >= n) break;
		jacob.push_back(next);
	}

	result.push_back(0);
	std::vector<int>::iterator it = ++jacob.begin();
	// est-ce que cela ajoute bien la fin apres le dernier jacobsthal ?
	while (it != jacob.end() - 1)
	{
		int	prev = *it;
		++it;
		int	next = *it;
		result.push_back(next);
		for (int i = prev + 1; i < next; i++)
		{
			result.push_back(i);
		}
	}
	return (result);
}

void	PmergeMe::_sort(std::vector<int>& arr)
{
	std::vector<int> main;
	std::vector<int> idx_main;
	std::vector<int> pending;
	std::vector<int> non_participating;
	
	if (arr.size() <= 1)
		return ;

	if (arr.size() % 2 != 0)
		non_participating.push_back(arr.back());

	// creating of pair winner (main) and pending
	for (int i = 0; i + 1 < (int)arr.size(); i += 2)
	{
		int a = arr[i];
		int b = -1;
		if (arr[i + 1])
			b = arr[i + 1];
		if (a && b != -1)
		{
			main.push_back(std::max(a, b));
			idx_main.push_back(i);
			pending.push_back(std::min(a, b));
		}
	}

	_sort(main);

	std::vector<int> jacobsthal = sequenceJacobsthal((int) pending.size());

	int jaco = jacobsthal.size() - 1;
	if (jaco > (int) pending.size())
		jaco = pending.size() - 1;
	for (int i = jaco; i >= 0; i--)
	{
		// insert number of pending with sequence insert based of jacobsthal
		int idx = jacobsthal[i];
		if (idx >= (int)pending.size())
			break;
		int value = pending[idx];
		std::vector<int>::iterator it = lower_bound(main.begin(), main.begin() + idx_main[i], value);
		main.insert(it, value);
		
		// update pos winner with idx_main
		int insert_pos = std::distance(main.begin(), it);
		for (int i = 0; i < (int)pending.size(); i++)
		{
			if (idx_main[i] >= insert_pos)
				idx_main[i]++;
		}
	}

	// est-ce qu'il y a besoin d'une boucle ? pas sure
	for (long unsigned int i = 0; i < non_participating.size(); i++)
	{
		std::vector<int>::iterator it = lower_bound(main.begin(), main.end(), non_participating[i]);
		main.insert(it, non_participating[i]);
	}

	arr = main;
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
	_sort(_vector);
	gettimeofday(&endVector, NULL);

	// gettimeofday(&startDeque, NULL);
	// // _mergeSort(_deque);
	// gettimeofday(&endDeque, NULL);

	_printEnd(startVector, endVector, startDeque, endDeque);
}