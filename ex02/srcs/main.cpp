#include "PmergeMe.hpp"

int	main (int ac, char** av)
{
	// check the number of arguments
	if (ac < 2)
	{
		std::cerr << "Error: not enough argument" << std::endl;
		return (1);
	}

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
				return (1);
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
			return (1);
		}

		// reject 0
		if (number == 0)
		{
			std::cerr << "Error: " << av[i] << std::endl;
			return (1);
		}
		std::cout << number << std::endl;
	}
	return (0);
}
