#include "../includes/RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}
RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

static bool	isOperator(char c)
{
	if (c == '*')
		return (true);
	if (c == '/')
		return (true);
	if (c == '+')
		return (true);
	if (c == '-')
		return (true);
	return (false);
}

void	RPN::parsing(std::string const& arg) const
{
	if (!(isdigit(arg[0]) && (isdigit(arg[arg.length() - 1])) || isOperator(arg[arg.length() - 1])))
		throw std::invalid_argument("bad input");

	for (size_t i = 0; i < arg.length(); i++)
	{
		if (isOperator(arg[i]) || isdigit(arg[i]))
		{
			i++;
			if (arg[i] == ' ' && i != arg.length())
				;
			else if (i != arg.length())
			{
				std::cout << "in if: " << arg[i] << "\n";
				throw std::invalid_argument("bad input");
			}
		}
		else
		{
			std::cout << arg[i] << "\n";
			throw std::invalid_argument("bad input");
		}
	}
}

// static double	operation()
// {
// 	return (0);
// }

// void	RPN::processRPN()
// {
// 	int	len = expr.lengh();

// 	for (int i = 0; i != len - 1; i++)
// 	{
// 		if (!isOperator(expr[i].c_str()))
// 			_stack.push(expr[i]);
// 		else
// 		{
// 			a = _stack.pop();
// 			b = _stack.pop();
// 			c = operation(a, b);
// 			_stack.push(c);
// 		}
// 	}
// 	return (_stack.pop());
// }
