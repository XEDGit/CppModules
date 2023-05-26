#include <easyfind.hpp>
#include <set>
#include <list>
#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: not enough arguments" << std::endl << "Usage: " << argv[0] << " <value to find>" << std::endl;
		return -1;
	}
	std::set<int> s;
	s.insert(5);
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(2);
	std::list<int> l;
	l.push_back(5);
	l.push_back(3);
	l.push_back(1);
	l.push_back(4);
	l.push_back(2);
	std::vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	int n = atoi(argv[1]);
	std::cout << easyfind(s, n) << " " << easyfind(l, n) << " " << easyfind(v, n);
}
