#include	"BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}
	if (!BitcoinExchange::checkInputFile(av[1]))
	{
		
		return (1);
	}

	return (0);
}
