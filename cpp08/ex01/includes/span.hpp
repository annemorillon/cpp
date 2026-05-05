#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>

class Span
{
	public:

		Span();
		Span(unsigned int N);
		~Span();
		Span(Span const& copy);
		Span	&operator=(Span const& old);

		void	addNumber(int value);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

	private:

		unsigned int	_size;
		std::vector<int> _vect;

};

#endif