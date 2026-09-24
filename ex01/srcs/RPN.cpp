#include	"RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{

	this->_stack = other._stack;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

bool	RPN::calculateRPN(std::string av)
{
	std::istringstream	iss(av);
	std::string			token;

	while (iss >> token)
	{
		// check if the token contains only one character
		if (token.size() != 1)
		{
			std::cerr << "Error: invalid argument" << std::endl;
			return (false);
		}

		// check if the token is digit between 0 and 9 or a valid operator (+, -, /, *)
		if ((token[0] < '0' || token[0] > '9') && (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
		{
			std::cerr << "Error: invalid argument" << std::endl;
			return (false);
		}
	}
}