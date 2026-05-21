#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include	<iostream>
# include	<algorithm>
# include	<deque>
# include	<vector>
# include	<sys/time.h>
# include	<cstring>

# define RESET	"\033[0m"
# define RED	"\033[31m"

class PmergeMe {
	public :

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe &operator=(const PmergeMe& other);
	
		void				process(char **av);

	private :

		void				_parsing(char **av);

		void				_sort(std::vector<int>& arr);
		void				_mergeSort(std::deque<int>& arr);

		std::vector<int>::iterator	findIterator(int n);

		long				_calculateTime(struct timeval start, struct timeval end) const;
		void				_printEnd(struct timeval startVector, struct timeval endVector, struct timeval startDeque, struct timeval endDeque);

		std::vector<int>	_before;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
};

template <typename T>
void print(T& tab)
{
	typename T::iterator it = tab.begin();

	while (it != tab.end())
	{
		std::cout << *it;
		++it;
		if (it != tab.end())
			std::cout << " ";
	}
	// if (it == tab.begin())
	// 	throw std::runtime_error("value not found");
	std::cout << "\n";
}
	
#endif