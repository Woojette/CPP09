#ifndef PMERGEME_HPP
# define    PMERGEME_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <deque>
# include <sstream>
# include <utility> // std::pair

class PmergeMe
{
  private:
		std::vector<int>	_vectorInputs; // store the input integers in a vector
		std::deque<int>	_dequeInputs; // store the input integers in a deque

  public:
		PmergeMe();
		~PmergeMe();

		bool	parseInput(int ac, char **av);
		void	printBefore() const;
		void	sortFordJohnson();
};



#endif
