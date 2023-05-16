#include "../include/RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	_stack = rhs._stack;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		RPN::add(void)
{
	int	value;

	value = _stack.top();
	_stack.pop();
	value = _stack.top() + value;
	_stack.pop();
	_stack.push(value);
}

void		RPN::sub(void)
{
	int	value;

	value = _stack.top();
	_stack.pop();
	value = _stack.top() - value;
	_stack.pop();
	_stack.push(value);
}

void		RPN::mult(void)
{
	int	value;

	value = _stack.top();
	_stack.pop();
	value = _stack.top() * value;
	_stack.pop();
	_stack.push(value);
}

void		RPN::div(void)
{
	int	value;

	value = _stack.top();
	_stack.pop();
	value = _stack.top() / value;
	_stack.pop();
	_stack.push(value);
}

std::string	RPN::compute(std::string str)
{
	std::ostringstream	res;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]) || (str[i] == '-' && str[i + 1] && isdigit(str[i + 1]) ))
		{
			if (str[i] == '-')
				_stack.push((str[++i] - 48) * -1);
			else
				_stack.push(str[i] - 48);
		}
		else if (str[i] == '+' && _stack.size() > 1)
			add();
		else if (str[i] == '-' && _stack.size() > 1)
			sub();
		else if (str[i] == '*' && _stack.size() > 1)
			mult();
		else if (str[i] == '/' && _stack.size() > 1)
			div();
		else if (str[i] != ' ')
			return ("Error");
	}
	if (_stack.size() != 1)
		return ("Error");
	res << _stack.top();
	return res.str();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */