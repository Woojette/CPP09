#include	"BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}

	BitcoinExchange	btc;

	if (!btc.inputProcess(av[1]))
	{
		return (1);
	}

	return (0);
}
