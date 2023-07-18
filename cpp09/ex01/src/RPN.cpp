#include <RPN.hpp>

inline bool	is_sign(const std::string& s)
{
	if (s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*')
		return true;
	return false;
}

RPN::RPN(std::stack<std::string> argv)
{
	while (argv.size() > 0)
	{
		if (argv.top()[1] || (!std::isdigit(argv.top()[0]) && !is_sign(argv.top())))
			throw std::logic_error("not one digit or a sign");
		if (!is_sign(argv.top()))
		{
			stack.push(std::stoi(argv.top()));
			argv.pop();
			continue ;
		}
		else if (stack.size() < 2)
			throw std::logic_error("not enough operands");
		std::string sign = argv.top();
		argv.pop();
		int v1, v2;
		v2 = stack.top();
		stack.pop();
		v1 = stack.top();
		stack.pop();
		
		switch (sign[0])
		{
			case '*':
				v1 = v1 * v2;
				break;
			case '+':
				v1 = v1 + v2;
				break;
			case '-':
				v1 = v1 - v2;
				break;
			case '/':
				v1 = v1 / v2;
				break;
		}

		stack.push(v1);
	}

	if (stack.size() != 1)
		throw std::logic_error("expression not complete");
	std::cout << stack.top() << std::endl;
}

RPN::RPN(const RPN &old)
{
	*this = old;
}

RPN::~RPN()
{
}

RPN	&RPN::operator =(const RPN &old)
{
	stack = old.stack;
	return *this;
}
