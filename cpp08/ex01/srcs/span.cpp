#include "span.hpp"

Span::Span(): _size(0)
{}

Span::Span(unsigned int N): _size(N)
{}

Span::~Span()
{}

Span::Span(Span const& copy): _size(0)
{
	*this = copy;
}

Span	&Span::operator=(Span const& old)
{
	if (this != &old)
	{
		_size = old._size;
		_vect = old._vect;
	}
	return (*this);
}

void	Span::addNumber(int value)
{
	if (_vect.size() < _size)
		_vect.push_back(value);
	else
		throw std::length_error("Array is full");
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		if (_vect.size() < _size)
			_vect.push_back(*begin);
		else
			throw std::length_error("Array is full");
		*begin++;
	}
}

int		Span::shortestSpan() //plus courte distance // exception si pas de nombre
{
	if (_size < 2 || _vect.size() < 2)
		throw std::invalid_argument("Size is too small");
	std::vector<int> copy = _vect;
	
	std::sort(copy.begin(), copy.end());
	std::vector<int> diffs(copy.size());
	std::adjacent_difference(copy.begin(), copy.end(), diffs.begin());

	std::vector<int>::iterator it = std::min_element(diffs.begin() + 1, diffs.end());
	return (*it);
}

int		Span::longestSpan() //plus longue distance // exception si pas de nombre
{
	if (_size < 2 || _vect.size() < 2)
		throw std::invalid_argument("Size is too small");
	std::vector<int>::iterator min = std::min_element(_vect.begin(), _vect.end());
	std::vector<int>::iterator max = std::max_element(_vect.begin(), _vect.end());

	int longest = *max - *min;

	return (longest);
}
