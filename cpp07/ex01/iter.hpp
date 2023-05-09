#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	iter(T* a, unsigned int len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(a[i]);
}

template <typename T>
void	print(T& a)
{
	std::cout << a << std::endl;
}

#endif