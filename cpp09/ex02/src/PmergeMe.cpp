#include <PmergeMe.hpp>

static void	error(std::string msg)
{
	std::cerr << msg << std::endl;
	exit(1);
}

PmergeMe::PmergeMe(char** argv)
{
	outcast = -1;

	try
	{
		for (int i = 1; argv[i]; i++)
		{
			if (!argv[i][0])
				error("Argument not valid");
			for (size_t j = 0; argv[i][j]; j++)
			{
				if (!std::isdigit(argv[i][j]))
					error("Argument not valid");
			}
			push(std::stoi(argv[i]));
		}
	}
	catch(const std::exception& e)
	{
		error("Stoi failed");
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
	deq = old.deq;
	vec = old.vec;
	return *this;
}

void PmergeMe::push(int num)
{
	deq.push_front(num);
	vec.push_back(num);
}

void PmergeMe::pop(void)
{
	deq.pop_front();
	vec.pop_back();
}

static void get_final_times(std::chrono::microseconds (&end_time)[4], std::chrono::high_resolution_clock::time_point (&time)[4])
{
	end_time[0] = std::chrono::duration_cast<std::chrono::microseconds>(time[1] - time[0]);
	end_time[1] = std::chrono::duration_cast<std::chrono::microseconds>(time[2] - time[1]);
	end_time[2] = std::chrono::duration_cast<std::chrono::microseconds>(time[3] - time[2]);
	end_time[3] = std::chrono::duration_cast<std::chrono::microseconds>(time[3] - time[0]);
}

void	PmergeMe::sort(void)
{
	std::chrono::high_resolution_clock::time_point time_vec[4], time_deq[4];
	std::vector<int> before = vec;
	
	if (deq.size() != 1)
	{
		sort_one_container(vec, time_vec);
		// sort_one_container(deq, time_deq);
	}

	// std::cout << "Before: ";
	// for (auto i = before.begin(); i != before.end(); i++)
	// 	std::cout << *i << " ";

	// std::cout << std::endl << "After: ";
	for (auto i = vec.rbegin(); i != vec.rend(); i++)
		std::cout << *i << " ";

	// std::chrono::microseconds end_time_vec[4], end_time_deq[4];
	// get_final_times(end_time_vec, time_vec);
	// get_final_times(end_time_deq, time_deq);

	// std::cout << std::endl \
	// << "Time to make a new container with elements in pairs with std::vector : " << end_time_vec[0].count() << "us" << std::endl \
	// << "Time to sort the pairs container by the first element with std::vector : " << end_time_vec[1].count() << "us" << std::endl \
	// << "Time to sort the pairs container with merge-insert algorithm with std::vector : " << end_time_vec[2].count() << "us" << std::endl \
	// << "Time to process a range of " << vec.size() << " elements with std::vector : " << end_time_vec[3].count() << "us" << std::endl \
	// << "Time to make a new container with elements in pairs with std::deque : " << end_time_deq[0].count() << "us" << std::endl \
	// << "Time to sort the pairs container by the first element with std::deque : " << end_time_deq[1].count() << "us" << std::endl \
	// << "Time to sort the pairs container with merge-insert algorithm with std::deque : " << end_time_deq[2].count() << "us" << std::endl \
	// << "Time to process a range of " << deq.size() << " elements with std::deque : " << end_time_deq[3].count() << "us" << std::endl;
}

void PmergeMe::sort_impl(int i, std::deque<std::pair<int, int> >& pairs)
{
	int bin_i = deq.size() / 2, delta = bin_i, target = pairs[i].second;

	while (1)
	{ 
		delta = delta / 2;
		int deq_tar = deq[bin_i], deq_tar1 = deq[bin_i + 1];
		if (!delta)
			delta++;
		if (target >= deq_tar && target <= deq_tar1)
		{
			deq.insert(deq.cbegin() + bin_i + 1, target);
			break ;
		}
		else if (target < deq_tar)
			bin_i -= delta;
		else if (target > deq_tar)
			bin_i += delta;
		if (bin_i < 0)
		{
			deq.push_front(target);
			break ;
		}
	}
}

void	PmergeMe::sort(std::deque<std::pair<int, int> >& pairs)
{
	deq.clear();
	for (int i = pairs.size() - 1; i >= 0; i--)
		deq.push_front(pairs[i].first);
	
	int i = 2, jac_i = 1;

	deq.push_front(pairs[0].second);
	while (i < pairs.size())
	{
		sort_impl(i, pairs);
		if (i == jacob_seq[jac_i - 1] + 1)
			i = jacob_seq[++jac_i];
		else
			i--;
	}
	i = jacob_seq[jac_i - 1] + 1;
	while (i < pairs.size())
	{
		sort_impl(i, pairs);
		i++;
	}
	if (outcast != -1)
	{
		if (outcast >= deq.back())
			deq.push_back(outcast);
		else
		{
			std::deque<std::pair<int, int> > tmp;
			tmp.push_front(std::make_pair(0, outcast));
			sort_impl(0, tmp);
		}
	}
}

void PmergeMe::sort_impl(int i, std::vector<std::pair<int, int> >& pairs)
{
	int bin_i = vec.size() / 2, delta = bin_i, target = pairs[i].second;

	while (1)
	{
		int vec_tar = vec[bin_i], vec_tar1 = vec[bin_i + 1];
		delta = delta / 2;
		if (!delta)
			delta++;
		if (target <= vec_tar && target >= vec_tar1)
		{
			vec.insert(vec.cbegin() + bin_i + 1, target);
			break ;
		}
		else if (target > vec_tar)
			bin_i -= delta;
		else if (target < vec_tar)
			bin_i += delta;
		if (bin_i > vec.size() - 1)
		{
			vec.push_back(target);
			break ;
		}
	}
}

void	PmergeMe::sort(std::vector<std::pair<int, int> >& pairs)
{
	vec.clear();
	for (int i = 0; i < pairs.size(); i++)
		vec.push_back(pairs[i].first);
	
	int i = pairs.size() - 3, jac_i = 1;

	vec.push_back(pairs[pairs.size() - 1].second);
	while (i >= 0)
	{
		sort_impl(i, pairs);
		if (i == pairs.size() - 1 - (jacob_seq[jac_i - 1] + 1))
			i = pairs.size() - 1 - jacob_seq[++jac_i];
		else
			i++;
	}
	i = pairs.size() - 1 - (jacob_seq[jac_i - 1] + 1);
	while (i >= 0)
	{
		sort_impl(i, pairs);
		i--;
	}
	if (outcast != -1)
	{
		if (outcast >= vec.front())
			vec.insert(vec.cbegin(), outcast);
		else
		{
			pairs.push_back(std::make_pair(0, outcast));
			sort_impl(pairs.size() - 1, pairs);
		}
	}
}
