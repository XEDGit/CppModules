#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN
{
	private:
		std::stack<int>	stack;
	public:
				RPN(char** argv);
				~RPN();
				RPN(const RPN &old);
		RPN&   operator=(const RPN &old);
};

#endif
