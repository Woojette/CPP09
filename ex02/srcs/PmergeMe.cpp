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



void	PmergeMe::sortValues(std::vector<int> >& values)
{
	if (values.size() < 2)
		return ;

	std::vector<std::pair<int, int> >	pairs;
	std::vector<int> secondValues;

	for (size_t i = 0; i + 1 < values.size(); i += 2)
	{
		int	first = values[i];
		int	second = values[i+1];
	
		if (first > second)
			std::swap(first, second);
		pairs.push_back(std::pair<int, int>(first, second));
		secondValues.push_back(second);
	}

	sortValues(secondValues);

	std::vector<int>	sortedValues;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].second == secondValues[0])
		{
			sortedValues.push_back(pairs[i].first);
			sortedValues.push_back(pairs[i].second);
			break ;
		}
	}

}

void	PmergeMe::sortFordJohnson()
{
	// base case: zero or one element is already sorted
	if (_vectorInputs.size() < 2)
		return ;

	// 1-1. create ordered pairs
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

	// 1-2. save the unpaired element
	int	straggler = 0;
	if (_vectorInputs.size() % 2 != 0)
		straggler = _vectorInputs.back();
	(void)straggler;


	std::vector<int>	firstValues;
	std::vector<int>	secondValues;

	for (size_t i = 0; i < pairs.size(); i += 1)
	{
		firstValues.push_back(pairs[i].first);
		secondValues.push_back(pairs[i].second);
	}

	


// [1 6] [5 8] [7 4] [2 0] -> 1 5 4 0
// [6 8] [7 2] -> 6 2
// [8 7] -> 7
// 8 jacobsthal = insertion binaire

// 1. pairs
// 2. garder des grands

// 3. trier des grands
// 4. inserer les petits dans 3


	sortPairsBySecond(pairs);


	// size_t	blockSize = 1;

	// repeat while there are enough pairs to compare 2 blocks
	// while (2 * blockSize <= pairs.size())
	// {
	// 	compare 2 adjacent blocks, then move to the next 2 blocks
	// 	for (size_t start = 0; start + 2 * blockSize <= pairs.size(); start += 2 * blockSize)
	// 	{
	// 		int	firstMax = pairs[start + (blockSize - 1)].second;
	// 		int	secondMax = pairs[start + (2 * blockSize - 1)].second;

	// 		if (firstMax > secondMax)
	// 		{
	// 			// swap 2 adjacent blocks, one pair at a time
	// 			for (size_t j = 0; j < blockSize; j++)
	// 			{
	// 				std::pair<int, int>	temp = pairs[start + j];
	// 				pairs[start + j] = pairs[start + blockSize + j];
	// 				pairs[start + blockSize + j] = temp;
	// 			}
	// 		}
	// 	}
	// 	blockSize *= 2;
	// }



	std::cout << "Pairs after block comparison: ";
	for (size_t i = 0; i < pairs.size(); i++)
	{
			std::cout << "(" << pairs[i].first
								<< "," << pairs[i].second << ") ";
	}
	std::cout << std::endl;

}
