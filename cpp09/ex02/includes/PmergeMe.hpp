#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include	<iostream>
# include	<algorithm>
# include	<deque>
# include	<vector>
# include	<sys/time.h>
# include	<cstring>
# include	<typeinfo>
# include	<limits.h>

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

		void				_createPairs(T& arr, std::vector<std::pair<int, int> >& pairs, T& pending, int& non_participating);
		
		T					_sequenceInsertion(int n);
		T					_sequenceJacobsthal(int n);

		void				_insertFirst(T& main, T& idx_main, T& pending, std::vector<bool>& inserted);
		void				_insertPending(T& main, T& idx_main, T& pending);
		void				_updatePosWinner(int insert_pos, T& idx_main);

		void				_sort(T& arr);

		long				_calculateTime(struct timeval start, struct timeval end) const;
		void				_printEnd(struct timeval start, struct timeval end);
		void				_checkSort();

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
	std::cout << "\n";
}

#include "../srcs/PmergeMe.cpp"
	
#endif