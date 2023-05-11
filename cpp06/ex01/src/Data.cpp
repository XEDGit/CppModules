#include <Data.hpp>

Data::Data(std::string& name) : name(name)
{
}

Data::Data(const Data &old)
{

	*this = old;
}

Data::~Data()
{
}

Data	&Data::operator =(const Data &old)
{
	name = old.name;
	return *this;
}
