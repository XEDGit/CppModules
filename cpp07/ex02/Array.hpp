#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>

template <typename T>
class Array {
	private:
		T*				array;
		unsigned int	_size;
	public:
						Array(unsigned int nsize = 0);
						Array(Array<T>& old);
						~Array();
		Array<T>&		operator=(Array<T>& old);
		T&				operator[](unsigned int index);
		unsigned int	size();
};

template <typename T>
Array<T>::Array(unsigned int nsize)
{
	_size = nsize + 1;
	array = new T[_size];
	array[nsize] = 0;
}

template <typename T>
Array<T>::Array(Array<T> &old)
{
	*this = old;
}

template <typename T>
Array<T>::~Array()
{
	delete [] array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& old)
{
	array = new T[old._size];
	std::memcpy(array, old.array, sizeof(T) * old._size);
	_size = old._size;
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return array[index];
}

template <typename T>
unsigned int Array<T>::size()
{
	return _size;
}

#endif