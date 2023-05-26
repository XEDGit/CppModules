#ifndef SPAN_HPP
# define SPAN_HPP

# include <iterator>
# include <stdexcept>
# include <iostream>
# include <vector>
# include <set>

class Span
{
	private:
		std::multiset<int>	sorted;
		std::vector<int>	original;
		unsigned int		length;
		unsigned int		cursor;
	public:
						Span(unsigned int length);
						~Span();
						Span(const Span &old);
		Span&   		operator=(const Span &old);
		void			addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		template<class Iterator>
		void			addIterator(Iterator begin, Iterator end)
		{
			if (cursor + std::distance(begin, end) > length)
				throw std::out_of_range("Range of iterators cannot fit Span");
			while (begin != end)
			{
				original[cursor++] = *begin;
				sorted.insert(*begin);
				begin++;
			}
		}
};

#endif
