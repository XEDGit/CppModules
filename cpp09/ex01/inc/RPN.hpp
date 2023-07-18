#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <algorithm> 

class RPN
{
	private:
		std::stack<int>	stack;
	public:
				RPN(std::stack<std::string> argv);
				~RPN();
				RPN(const RPN &old);
		RPN&   operator=(const RPN &old);
};

#endif
