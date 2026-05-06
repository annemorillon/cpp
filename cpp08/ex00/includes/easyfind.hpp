#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template <typename T>
typename T::iterator	easyfind(T& type, int nb)
{
	typename T::iterator it = find(type.begin(), type.end(), nb);
	 if (it == type.end())
		throw std::runtime_error("value not found");
	return it;
}

#endif