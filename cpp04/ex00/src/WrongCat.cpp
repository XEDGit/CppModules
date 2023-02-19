#include <WrongCat.hpp>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& old)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = old;
}

WrongCat&	WrongCat::operator=(const WrongCat& old)
{
	std::cout << "WrongCat assignement operator called" << std::endl;
	type = old.type;
	return *this;
}

std::string WrongCat::getType() const
{
	return type;
}
