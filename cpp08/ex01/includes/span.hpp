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
		template <typename T> void	addNumbers(T begin, T end)
		{
			while (begin != end)
			{
				if (_vect.size() < _size)
					_vect.push_back(*begin);
				else
					throw std::length_error("Array is full");
				*begin++;
			}
		};
		int		shortestSpan();
		int		longestSpan();

	private:

		unsigned int	_size;
		std::vector<int> _vect;

};

#endif