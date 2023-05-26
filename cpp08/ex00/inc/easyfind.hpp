#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
long	easyfind(T container, int element) {
	unsigned long ret = std::distance(container.begin(), std::find(container.begin(), container.end(), element));
	if (ret == container.size())
		return -1;
	else
		return ret;
}

#endif