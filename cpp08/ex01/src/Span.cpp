#include <Span.hpp>

Span::Span(unsigned int length) : length(length)
{
	original.resize(length);
	cursor = 0;
}

Span::Span(const Span &old)
{
	*this = old;
}

Span::~Span()
{
}

Span    &Span::operator =(const Span &old)
{
	cursor = old.cursor;
	length = old.length;
	original = std::vector<int>(old.original);
	sorted = std::multiset<int>(old.sorted.begin(), old.sorted.end());
	return *this;
}

void Span::addNumber(int num)
{
	if (cursor == length)
		throw std::out_of_range("Cannot add element to Span");
	original[cursor++] = num;
	sorted.insert(num);
}

unsigned int Span::shortestSpan()
{
	unsigned int	result = -1;
	unsigned int	last = *sorted.begin();

	if (cursor < 2)
		throw std::out_of_range("Not enough elements in Span to calculate shortest span, minimun is 2");
	std::multiset<int>::iterator it = sorted.begin(), end;
	for (it++, end = sorted.end(); it != end; last = *it, it++)
		if (*it - last < result)
			result = *it - last;
	return result;
}

unsigned int Span::longestSpan()
{
	if (cursor < 2)
		throw std::out_of_range("Not enough elements in Span to calculate shortest span, minimun is 2");
	return *sorted.rbegin() - *sorted.begin();
}
