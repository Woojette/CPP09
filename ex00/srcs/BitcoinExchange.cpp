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

	// check if the input file is empty or has invalid format
	std::string	line;
	if (!std::getline(file, line))
	{
		std::cerr << "Error: input file is empty." << std::endl;
		return (false);
	}

	// check if the first line is "date | value"
	if (line != "date | value")
	{
		std::cerr << "Error: invalid input file format." << std::endl;
		return (false);
	}

	while (std::getline(file, line))
	{

	}

	return (true);
}
