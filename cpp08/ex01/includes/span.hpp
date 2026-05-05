#ifndef SPAN_HPP
# define SPAN_HPP

# include "iostream"
# include <vector>

class Span
{
	public:

		Span();
		Span(unsigned int N);
		~Span();
		Span(Span const& copy);
		Span	&operator=(Span const& old);

		void	addNumber(int value);
		int		shortestSpan();
		int		longestSpan();

	private:

		unsigned int	_size;
		std::vector<int> _vect;

};

#endif