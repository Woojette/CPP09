#ifndef PMERGEME_HPP
# define    PMERGEME_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <deque>
# include <sstream>

class PmergeMe
{
  private:
		std::vector<int>	_vectorInputs; // store the input integers in a vector
		std::deque<int>	_dequeInputs; // store the input integers in a deque
  public:
		PmergeMe();
		~PmergeMe();

		void	printBefore() const;
		bool	parseInput(int ac, char **av);
};



#endif
