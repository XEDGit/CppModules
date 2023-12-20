#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <chrono>

# define TEMPLATE_ONE_CONTAINER template <typename, typename> class C, typename T


template <TEMPLATE_ONE_CONTAINER >
concept pushfrontmember = requires(C<T, std::allocator<T>>& src, T val) { src.push_front(val); };

class PmergeMe
{
	private:
		const int			jacob_seq[21] = {
			1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845,
			43691, 87381, 174763, 349525, 699051, 1398101
		};
		std::vector<int>	vec;
		std::deque<int>		deq;
		int					outcast;
		void				sort_impl(int i, std::deque<std::pair<int, int> >& pairs);
		void				sort_impl(int i, std::vector<std::pair<int, int> >& pairs);
		void				sort(std::deque<std::pair<int, int> >& pairs);
		void				sort(std::vector<std::pair<int, int> >& pairs);

		template <TEMPLATE_ONE_CONTAINER >
		void	sort_one_container(C<T, std::allocator<T>>& target, std::chrono::high_resolution_clock::time_point (&times)[4])
		{
			times[0] = std::chrono::high_resolution_clock::now();
			C<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs_container;
			outcast = convert_to_pairs(target, pairs_container);
			times[1] = std::chrono::high_resolution_clock::now();
			sort_pairs(pairs_container, pairs_container.size() - 1);
			times[2] = std::chrono::high_resolution_clock::now();
			sort(pairs_container);
			times[3] = std::chrono::high_resolution_clock::now();
		}

		template <TEMPLATE_ONE_CONTAINER >
		static void	sort_pairs_internally(C<T, std::allocator<T>>& target)
		{
			for (typename C<T, std::allocator<T>>::iterator it = target.begin(); it != target.end(); it++)
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
		void recursive_insert(C<T, std::allocator<T>>& target, int n)
		{
			if (n <= 1) 
				return;
			recursive_insert(target, n-1); 

			T last = target[n - 1]; 
			int j = n - 2; 
			while (j >= 0 && target[j].first > last.first) 
			{
				target[j+1] = target[j]; 
				j--; 
			} 
			target[j+1] = last; 
		}

		template <TEMPLATE_ONE_CONTAINER >
		void	sort_pairs(C<T, std::allocator<T>>& target, int n)
		{
			if (n < 1)
				return ;
			recursive_insert(target, n + 1);
		}

		template <TEMPLATE_ONE_CONTAINER >
		requires pushfrontmember<C, T>
		static int	convert_to_pairs_impl(C<T, std::allocator<T>>& src, C<std::pair<T, T>, std::allocator<std::pair<T, T>>>& dst)
		{
			for (typename C<T, std::allocator<T>>::iterator it = src.begin(); it != src.end(); it++)
			{
				T last = *it;
				it++;
				if (it == src.end())
					return last;
				dst.push_front(std::make_pair(last, *it));
			}
			return (-1);
		}

		template <TEMPLATE_ONE_CONTAINER >
		static int	convert_to_pairs_impl(C<T, std::allocator<T>>& src, C<std::pair<T, T>, std::allocator<std::pair<T, T>>>& dst)
		{
			for (typename C<T, std::allocator<T>>::iterator it = src.begin(); it != src.end(); it++)
			{
				T last = *it;
				it++;
				if (it == src.end())
					return last;
				dst.push_back(std::make_pair(last, *it));
			}
			return (-1);
		}

		template <TEMPLATE_ONE_CONTAINER >
		int	convert_to_pairs(C<T, std::allocator<T>>& src, C<std::pair<T, T>, std::allocator<std::pair<T, T>>>& dst)
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
