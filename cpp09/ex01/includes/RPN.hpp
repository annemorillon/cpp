#ifndef RPN_CPP
# define RPN_CPP

# include	<iostream>
# include	<stack>

# define RESET   "\033[0m"
# define RED     "\033[31m"

class RPN {
	public :

		RPN();
		~RPN();
		RPN(const RPN& copy);
		RPN &operator=(const RPN& other);

		void	parsing(std::string const& arg) const;
		void	processRPN(std::string const& expr);
	
	private :
		std::stack<double> _stack;
};

#endif