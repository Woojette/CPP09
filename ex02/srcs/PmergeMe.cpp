#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorInputs.size(); i++)
	{
		std::cout << _vectorInputs[i] << " ";
	}
	std::cout << std::endl; 
}


bool	PmergeMe::parseInput(int ac, char **av)
{
	// iterate through each argument
	for (int i = 1; i < ac; i++)
	{
		// check each character of each argument
		for (int k = 0; av[i][k]; k++)
		{
			// reject non-digit characters
			if (av[i][k] < '0' || av[i][k] > '9')
			{
				std::cerr << "Error: " << av[i] << std::endl;
				return (false);
			}
		}

		// convert the string to an integer
		std::stringstream	ss(av[i]);
		int	number;
		ss >> number;
	
		// check for conversion errors (ex. "", '') or integer overflow (int min/max)
		if (ss.fail())
		{
			std::cerr << "Error: " << av[i] << std::endl;
			return (false);
		}

		// reject 0
		if (number == 0)
		{
			std::cerr << "Error: " << av[i] << std::endl;
			return (false);
		}

		// add the validated integer to the vector
		_vectorInputs.push_back(number);

		// add the validated integer to the deque
		_dequeInputs.push_back(number);
	}
  return (true);
}