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
		_stack = other._stack;
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
	if (!(isdigit(arg[0]) && (isdigit(arg[arg.length() - 1]) || isOperator(arg[arg.length() - 1]))))
		throw std::invalid_argument("bad input");

	for (size_t i = 0; i < arg.length(); i++)
	{
		if (isOperator(arg[i]) || isdigit(arg[i]))
		{
			i++;
			if (arg[i] == ' ' && i != arg.length())
				;
			else if (i != arg.length())
				throw std::invalid_argument("bad input");
		}
		else
			throw std::invalid_argument("bad input");
	}
}

static double	operation(double a, double b, char operators)
{
	double result = 0;

	if (a == 0 && operators == '/')
		throw std::invalid_argument("division by zero");
	else if (operators == '/')
		result = b / a;
	else if (operators == '*')
		result = b * a;
	else if (operators == '+')
		result = b + a;
	else if (operators == '-')
		result = b - a;
	return (result);
}

void	RPN::processRPN(std::string const& expr)
{
	double a, b, c;
	int	len = expr.length();

	for (int i = 0; i != len; i++)
	{
		if (isdigit(expr[i]))
			_stack.push(expr[i] - '0');
		else if (expr[i] == ' ')
			;
		else
		{
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			c = operation(a, b, expr[i]);
			_stack.push(c);
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("bad input");
	std::cout << _stack.top() << "\n";
	_stack.pop();
	// return (_stack.pop());
}
