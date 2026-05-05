#include "span.hpp"

Span::Span(): _size(0), _vect(0)
{}

Span::Span(unsigned int N): _size(N), _vect(N)
{}

Span::~Span()
{}

Span::Span(Span const& copy): _size(0), _vect(0)
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
	if (_size != _vect.size())
		_vect.push_back(value);
	else
		throw std::length_error("Array is full");
}

int		Span::shortestSpan() //plus courte distance // exception si pas de nombre
{

}

int		Span::longestSpan() //plus longue distance // exception si pas de nombre
{
	
}
