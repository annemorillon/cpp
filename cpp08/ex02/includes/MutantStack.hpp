#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <vector>
# include <stack>
# include <algorithm>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(){ };
		~MutantStack(){ };
		MutantStack(const MutantStack& copy) : std::stack<T>(Copy) {};
		MutantStack &MutantStack(const MutantStack& old){
			std::stack<T>::operator=(old);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::iterator reverse_iterator;
		iterator rbegin(){
			return (this->c.rbegin());
		}
		iterator rend(){
			return (this->c.rend());
		}
};

#endif