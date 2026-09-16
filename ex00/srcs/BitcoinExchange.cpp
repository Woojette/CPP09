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
		// check the format of the line, it should be "YYYY-MM-DD | value"
		std::string::size_type	separatorPos = line.find(" | ");

		// check if the position of the separator is " | "
		if (separatorPos == std::string::npos || separatorPos != 10)
		{
			std::cerr << "Error: invalid input file format." << std::endl;
			continue ;
		}

		// check if the position of the separator is "yyyy-mm"
		std::string::size_type	firstDashPos = line.find("-");
		if (firstDashPos == std::string::npos || firstDashPos != 4)
		{
			std::cerr << "Error: invalid input file format." << std::endl;
			continue ;
		}

		// check if the position of the separator is "mm-dd"
		std::string::size_type	secondDashPos = line.find("-", 5);
		if (secondDashPos == std::string::npos || secondDashPos != 7)
		{
			std::cerr << "Error: invalid input file format." << std::endl;
			continue ;
		}

		// check if all characters in YYYY, MM, DD are digits
		bool	isNumeric = true;
		for (size_t i = 0; i < 10; i++)
		{
			if (i == 4 || i == 7)
				continue ;
			if (!(line[i] >= '0' && line[i] <= '9'))
			{
				std::cerr << "Error: invalid input file format." << std::endl;
				isNumeric = false;
				break ;
			}
		}
		if (!isNumeric)
			continue ;
	}

	return (true);
}
