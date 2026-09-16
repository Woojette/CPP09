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

		// check if the separator " | " is at the correct position
		if (separatorPos == std::string::npos || separatorPos != 10)
		{
			std::cerr << "Error: invalid input file format." << std::endl;
			continue ;
		}

		// check if the first dash "yyyy-mm" is at the correct position
		std::string::size_type	firstDashPos = line.find("-");
		if (firstDashPos == std::string::npos || firstDashPos != 4)
		{
			std::cerr << "Error: invalid input file format." << std::endl;
			continue ;
		}

		// check if the second dash "mm-dd" is at the correct position
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

		// extract YYYY, MM, DD as strings
		std::string	yearString = line.substr(0, 4);
		std::string	monthString = line.substr(5, 2);
		std::string	dayString = line.substr(8, 2);

		// convert YYYY to int
		std::stringstream	yearStream(yearString);
		int	yearInt;
		yearStream >> yearInt;

		// check if the year is valid
		if (yearInt < 1)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// convert MM to int
		std::stringstream	monthStream(monthString);
		int	monthInt;
		monthStream >> monthInt;

		// check if the month is valid
		if (monthInt < 1 || monthInt > 12)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::stringstream	dayStream(dayString);
		int	dayInt;
		dayStream >> dayInt;

		// check if the day is valid (not 00)
		if (dayInt < 1)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// check the months with 31 days
		if ((monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7 
			|| monthInt == 8 || monthInt == 10 || monthInt == 12) && dayInt > 31)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// check the months with 30 days
		if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// check february considering leap years
		if (monthInt == 2)
		{
			if ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)
			{
				if (dayInt > 29)
				{
					std::cerr << "Error: bad input => " << line << std::endl;
					continue ;
				}
			}
			else if (dayInt > 28)
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue ;
			}
		}
	}

	return (true);
}
