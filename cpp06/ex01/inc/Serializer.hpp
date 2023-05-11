#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <Data.hpp>

class Serializer
{
	private:
						Serializer(void);
						~Serializer();
						Serializer(const Serializer &old);
		Serializer& 	operator=(const Serializer &old);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
