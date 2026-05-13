#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN [inverted Polish mathematical expression]" << std::endl;
		return (1);
	}
	try
	{
		rpn.parsing(av[1]);
		rpn.processRPN(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << '\n';
	}
}

// ex02: deque + vector