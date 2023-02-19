#include <Fixed.hpp>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(int nvalue)
{
	std::cout << "Int constructor called" << std::endl;
	value = nvalue << fractionalBits;
}

Fixed::Fixed(float nvalue)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(nvalue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &old)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

Fixed::~Fixed()
{
		std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator =(const Fixed &old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = old.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(const int raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)value / (1 << fractionalBits);
}

int	Fixed::toInt(void) const
{
	return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &toPrint)
{
	out << toPrint.toFloat();
	return out;
}