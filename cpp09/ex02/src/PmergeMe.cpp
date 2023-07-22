#include <PmergeMe.hpp>

PmergeMe::PmergeMe(char **argv)
{
	outcast = -1;
	
	for (int i = 0; argv[i]; i++)
	{
		int past = std::stoi(argv[i++]);
		if (!argv[i])
		{
			outcast = past;
			break ;
		}
		std::pair<int, int> val(past, std::stoi(argv[i]));
		if (past < val.second)
		{
			val.first = val.second;
			val.second = past;
		}
		exec_deq.push_back(val);
		exec_vec.push_back(val);
	}
}

PmergeMe::PmergeMe(const PmergeMe &old)
{
	*this = old;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe	&PmergeMe::operator =(const PmergeMe &old)
{
	// TODO
	return *this;
}

void	PmergeMe::sort(void)
{

}
