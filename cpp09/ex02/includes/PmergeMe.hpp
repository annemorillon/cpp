#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include	<iostream>
# include	<algorithm>
# include	<deque>
# include	<vector>

# define RESET   "\033[0m"
# define RED     "\033[31m"

class PmergeMe {
	public :

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe &operator=(const PmergeMe& other);

		std::vector<int>	getAfterV() const;
		void				setAfterV(std::vector<int> const value);

		void	parsing(char **av);
		std::vector<int>	mergeSort(std::vector<int> arr);
		void	merge(std::vector<int> arr, std::vector<int> left, std::vector<int> right);
		void	printEnd();
	
	private :
		std::vector<int>	_before;
		std::vector<int>	_afterV;
		std::deque<int>		_afterD;

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
	if (it == tab.begin())
		throw std::runtime_error("value not found");
	std::cout << "\n";
}
	
#endif