#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "iostream"

template <typename T>
T&	easyfind(T type, int nb)
{
	if (type.empty())
		return ;
	int i = 0;
	while (type[i])
	{
		if (type[i] == nb)
			return (type[i])
	}

}

#endif