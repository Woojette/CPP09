#include "PmergeMe.hpp"

int	main (int ac, char** av)
{
	// check the number of arguments
	if (ac < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return (1);
	}

	PmergeMe	sorter;

	// validate and store the input integers
	if (!sorter.parseInput(ac, av))
		return (1);

	// display the input sequence before sorting (vector)
	sorter.printBefore();


	return (0);
}
