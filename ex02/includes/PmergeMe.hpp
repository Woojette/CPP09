#ifndef PMERGEME_HPP
# define    PMERGEME_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <deque>
# include <sstream>
# include <utility> // std::pair
# include <algorithm> // std::swap

class PmergeMe
{
  private:
		std::vector<int>	_vectorInputs; // store the input integers in a vector
		std::deque<int>	_dequeInputs; // store the input integers in a deque

		void	sortPairs(std::vector<std::pair<int, int> >& pairs); // sort the pairs in the original vector using a reference &

  public:
		PmergeMe();
		~PmergeMe();

		bool	parseInput(int ac, char **av);
		void	printBefore() const;
		void	sortFordJohnson();
};



#endif
