#ifndef RPN_HPP
# define    RPN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stack>
# include <sstream>

class RPN
{
private:
	std::stack<int>	_stack;
public:
	RPN();
    RPN(const RPN &other);
	~RPN();
    RPN& operator=(const RPN& other);

	bool	calculateRPN(std::string av);
};

#endif
