#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

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

void	PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorInputs.size(); i++)
	{
		std::cout << _vectorInputs[i] << " ";
	}
	std::cout << std::endl; 
}

void	PmergeMe::sortFordJohnson()
{
	// base case: zero or one element is already sorted
	if (_vectorInputs.size() <= 1)
		return ;

	// 1. create ordered pairs
	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i + 1 < _vectorInputs.size(); i += 2)
	{
		int	first = _vectorInputs[i];
		int	second = _vectorInputs[i + 1];

		if (first > second)
		{
			int	temp = first;
			first = second;
			second = temp;
		}
		pairs.push_back(std::pair<int, int>(first, second));
	}

	// 2. save the unpaired element
	int	straggler = 0;

	if (_vectorInputs.size() % 2 != 0)
		straggler = _vectorInputs.back();


}