#include <Span.hpp>
#include <algorithm>
int main(int argc, char **argv)
{
	int val = 2;
	// std::vector<int> vec;
	if (argc == 2)
		val = atoi(argv[1]);
	std::vector<int> vec(val, 10);
	// std::vector<int> vec2;
	// vec.push_back(100);
	// vec.push_back(1);
	// vec.push_back(88);
	// vec.push_back(5);
	// vec.push_back(55);
	// vec.push_back(2147483647);
	// vec.push_back(-2147483648);
	Span s(val);
	s.addIterator(vec.begin(), vec.end());
	std::cout << "short " << s.shortestSpan() << std::endl;
	std::cout << "long " << s.longestSpan() << std::endl;
}
