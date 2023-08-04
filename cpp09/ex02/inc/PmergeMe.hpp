#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <chrono>

# define TEMPLATE_CONTAINER_TO_PAIRS_CONTAINER template <typename, typename> class C, \
		  typename T, \
		  typename A = std::allocator<T>, \
		  typename AP = std::allocator<std::pair<T, T> > 

# define TEMPLATE_ONE_CONTAINER template <typename, typename> class C, \
		  typename T, \
		  typename A = std::allocator<T> 


template <TEMPLATE_ONE_CONTAINER >
concept pushfrontmember = requires(C<T, A>& src, T val) { src.push_front(val); };

class PmergeMe
{
	private:
		const int			jacob_seq[18] = {
			0, 2, 4, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095,
			8191, 16383, 32767, 65535, 131071
		};
		std::vector<int>	vec;
		std::deque<int>		deq;
		int					outcast;
		void				sort_impl(int i, std::deque<std::pair<int, int> >& pairs);
		void				sort_impl(int i, std::vector<std::pair<int, int> >& pairs);
		void				sort(std::deque<std::pair<int, int> >& pairs);
		void				sort(std::vector<std::pair<int, int> >& pairs);

		template <TEMPLATE_ONE_CONTAINER >
		void	sort_one_container(C<T, A>& target, std::chrono::high_resolution_clock::time_point (&times)[4])
		{
			times[0] = std::chrono::high_resolution_clock::now();
			C<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs_container;
			outcast = convert_to_pairs(target, pairs_container);
			times[1] = std::chrono::high_resolution_clock::now();
			sort_pairs(pairs_container);
			times[2] = std::chrono::high_resolution_clock::now();
			sort(pairs_container);
			times[3] = std::chrono::high_resolution_clock::now();
		}

		template <TEMPLATE_ONE_CONTAINER >
		static void	sort_pairs_internally(C<T, A>& target)
		{
			for (typename C<T, A>::iterator it = target.begin(); it != target.end(); it++)
			{
				T& val = *it;
				if (val.second > val.first)
				{
					T tmp = val;
					val.first = val.second;
					val.second = tmp.first;
				}
			}
		}

		template <TEMPLATE_ONE_CONTAINER >
		requires pushfrontmember<C, T, A>
		void	sort_pairs(C<T, A>& target)
		{
			for (int i = 0; i < target.size(); i++)
			{
				for (int j = 0; j < target.size() - 1; j++)
					if (target[j].first > target[j + 1].first)
						target[j].swap(target[j + 1]);
			}
		}

		template <TEMPLATE_ONE_CONTAINER >
		void	sort_pairs(C<T, A>& target)
		{
			for (int i = target.size() - 1; i >= 0; i--)
			{
				for (int j = target.size() - 1; j > 0; j--)
					if (target[j].first > target[j - 1].first)
						target[j].swap(target[j - 1]);
			}
		}

		template <TEMPLATE_CONTAINER_TO_PAIRS_CONTAINER >
		requires pushfrontmember<C, T, A>
		static int	convert_to_pairs_impl(C<T, A>& src, C<std::pair<T, T>, AP>& dst)
		{
			for (typename C<T, A>::iterator it = src.begin(); it != src.end(); it++)
			{
				T last = *it;
				it++;
				if (it == src.end())
					return last;
				dst.push_front(std::make_pair(last, *it));
			}
			return (-1);
		}

		template <TEMPLATE_CONTAINER_TO_PAIRS_CONTAINER >
		static int	convert_to_pairs_impl(C<T, A>& src, C<std::pair<T, T>, AP>& dst)
		{
			for (typename C<T, A>::iterator it = src.begin(); it != src.end(); it++)
			{
				T last = *it;
				it++;
				if (it == src.end())
					return last;
				dst.push_back(std::make_pair(last, *it));
			}
			return (-1);
		}

		template <TEMPLATE_CONTAINER_TO_PAIRS_CONTAINER >
		int	convert_to_pairs(C<T, A>& src, C<std::pair<T, T>, AP>& dst)
		{
			int ret = convert_to_pairs_impl(src, dst);
			sort_pairs_internally(dst);
			return (ret);
		}

	public:
					PmergeMe(char **argv);
					~PmergeMe();
					PmergeMe(const PmergeMe& old);
		PmergeMe&	operator=(const PmergeMe& old);
		void		push(int num);
		void		pop(void);
		void		sort(void);
};

#endif
