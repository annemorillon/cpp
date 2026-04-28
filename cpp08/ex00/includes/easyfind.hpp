#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "iostream"

template <typename T>
typename T::iterator	easyfind(T& type, size_t nb)
{
	if (type.empty())
		return ;
	for (iterator it1 = type.begin(); it1 != type.end(); ++it1)
	{
		if (it1 == nb)
			return (it1);
	}
}

#endif