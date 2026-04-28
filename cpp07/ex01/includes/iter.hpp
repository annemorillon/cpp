#ifndef ITER_HPP
# define ITER_HPP

# include "iostream"

template <typename T, typename F>
void iter(T *tab, const size_t len, F *function)
{
	for(size_t i = 0; i < len; i++)
		function(tab[i]);
}

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}
 
template <typename T>
void increment(T &x) {
    x++;
}

#endif