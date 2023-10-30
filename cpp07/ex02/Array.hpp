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
		unsigned int	size() const;

		class IndexOutOfBounds : public std::exception {
  			public:
				char * what () {
						return "Index out of bounds";
					}
};
};

template <typename T>
Array<T>::Array(unsigned int nsize)
{
	_size = nsize;
	array = new T[_size + 1];
}

template <typename T>
Array<T>::Array(Array<T> &old)
{
	array = new T[1];
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
	if (this != &old)
		delete [] array;
	_size = old._size;
	array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		array[i] = old.array[i];
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw IndexOutOfBounds();
	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif