#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>					vec;
		std::vector<std::pair<int, int>>	exec_vec;
		std::deque<int>						deq;
		std::deque<std::pair<int, int>>		exec_deq;
		int									outcast;
	public:
					PmergeMe(char **argv);
					~PmergeMe();
					PmergeMe(const PmergeMe &old);
		PmergeMe&	operator=(const PmergeMe &old);
		void		sort(void);
};

#endif
