#include	"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data("0000-00-00", 0)
{
	// std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor called" << std::endl;
}

void	BitcoinExchange::csvDatabase()
{
	
}

bool	BitcoinExchange::inputProcess(std::string filename)
{
	// check if the input file is valid and open it
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: invalid input file." << std::endl;
		return (false);
	}

	return (true);
}
