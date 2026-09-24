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

		// check if the token is digit between 0 and 9 or a valid operator (+, -, *, /)
		if ((token[0] < '0' || token[0] > '9') && (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
		{
			std::cerr << "Error: invalid argument" << std::endl;
			return (false);
		}

		// if the token is a digit (0 ~ 9), push it onto the stack
		if (token[0] >= '0' && token[0] <= '9')
		{
			int	number = token[0] - '0';
			this->_stack.push(number);
		}

		if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			// check if there are at least 2 operands to calculate
			if (this->_stack.size() < 2)
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return (false);
			}

			// extract the top two operands to apply the operator
			int secondOperand = this->_stack.top();
			this->_stack.pop();
			int	firstOperand = this->_stack.top();
			this->_stack.pop();

			int	resultOperand;

			if (token[0] == '+')
				resultOperand = firstOperand + secondOperand;
			else if (token[0] == '-')
				resultOperand = firstOperand - secondOperand;
			else if (token[0] == '*')
				resultOperand = firstOperand * secondOperand;
			else if (token[0] == '/' && secondOperand != 0)
				resultOperand = firstOperand / secondOperand;
			else
			{
				std::cerr << "Error: division by zero" << std::endl;
				return (false);
			}

			this->_stack.push(resultOperand);
		}
	}
	return (true);
}
