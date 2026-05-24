#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include	<iostream>
# include	<algorithm>
# include	<deque>
# include	<vector>
# include	<sys/time.h>
# include	<cstring>
# include	<typeinfo>

# define RESET	"\033[0m"
# define RED	"\033[31m"

template <typename T>
class PmergeMe {
	public :

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe &operator=(const PmergeMe& other);
	
		void				process(char **av);

	private :

		void				_parsing(char **av);

		void				_sort(T& arr);

		void				_createPairs(T& arr, T& main, T& idx_main, T& pending, int& non_participating);
		void				_updatePosWinner(typename T::iterator it, T& main, T& idx_main);
		void				_insertPending(T& main, T& idx_main, T& pending);

		void				_sortWithIndices(T& main, T& idx_main);

		T					_sequenceInsertion(int n);
		T					_sequenceJacobsthal(int n);

		long				_calculateTime(struct timeval start, struct timeval end) const;
		void				_printEnd(struct timeval start, struct timeval end);

		T	_before;
		T	_after;
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

#include "../srcs/PmergeMe.cpp"
	
#endif