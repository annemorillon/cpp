#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "iostream"
# include <stdlib.h>

template <typename T>
class Array
{
	public:

		Array();
		Array(size_t n);
		~Array();

		Array(Array const& copy);
		Array	&operator=(Array const& old);

		T&	operator[](size_t idx);
		const T&	operator[](size_t idx) const;
		size_t	size(void);

	private:
		size_t	_size;
		T		*_array;
};

template <typename T>
Array<T>::Array(): _size(0), _array(0){
}

template <typename T>
Array<T>::Array(size_t n): _size(n), _array(0){
	_array = new T[n]();
}

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
Array<T>::Array(Array const& copy): _size(0), _array(0){
	*this = copy;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const& old){
	if (this != &old)
	{
		delete[] _array;
		_size = old._size;
		if (_size == 0)
			_array = 0;
		else
		{
			_array = new T[_size]();
			for (size_t i = 0; i < _size; i++)
				_array[i] = old._array[i];
		}
	}
	return (*this);
}

template <typename T>
size_t	Array<T>::size(void)
{
	return (_size);
}

template <typename T>
const T&	Array<T>::operator[](size_t idx) const
{
	if (idx >= _size)
		throw std::out_of_range("Invalid Index");
	else
		return _array[idx];
}

template <typename T>
T&	Array<T>::operator[](size_t idx)
{
	if (idx >= _size)
		throw std::out_of_range("Invalid Index");
	else
		return _array[idx];
}

#endif