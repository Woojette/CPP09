#ifndef	BITCOINEXCHANGE_HPP
# define	BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <map>
# include <vector>
# include <deque>
# include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, double>	_data;
	//data["2014-02-08"] = 680
public:
	BitcoinExchange();
	// BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	// BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	loadDatabase();
};

#endif
