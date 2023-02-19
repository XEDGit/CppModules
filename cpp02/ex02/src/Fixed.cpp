#include <Fixed.hpp>

Fixed::Fixed(void)
{
	value = 0;
}

Fixed::Fixed(int nvalue)
{
	value = nvalue << fractionalBits;
}

Fixed::Fixed(float nvalue)
{
	value = roundf(nvalue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &old)
{
	*this = old;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator =(const Fixed &old)
{
	value = old.getRawBits();
	return *this;
}

bool	Fixed::operator <(const Fixed &r) const
{
	if (this->getRawBits() < r.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator >(const Fixed &r) const
{
	if (this->getRawBits() > r.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator <=(const Fixed &r) const
{
	if (this->getRawBits() <= r.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator >=(const Fixed &r) const
{
	if (this->getRawBits() >= r.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator ==(const Fixed &r) const
{
	if (this->getRawBits() == r.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator !=(const Fixed &r) const
{
	if (this->getRawBits() != r.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator +(const Fixed &r) const
{
	Fixed ret = Fixed(this->getRawBits() + r.getRawBits());
	return ret;
}

Fixed	Fixed::operator -(const Fixed &r) const
{
	Fixed ret = Fixed(this->getRawBits() - r.getRawBits());
	return ret;
}

Fixed	Fixed::operator *(const Fixed &r) const
{
	Fixed ret = Fixed(this->toFloat() * r.toFloat());
	return ret;
}

Fixed	Fixed::operator /(const Fixed &r) const
{
	Fixed ret = Fixed(this->toFloat() / r.toFloat());
	return ret;
}

Fixed	Fixed::operator++(int i)
{
	(void)i;
	Fixed ret = Fixed(*this);
	value += 1;
	return ret;
}

Fixed	Fixed::operator--(int i)
{
	(void)i;
	Fixed ret = Fixed(*this);
	value -= 1;
	return ret;
}

Fixed&	Fixed::operator++(void)
{
	value++;
	return *this;
}

Fixed&	Fixed::operator--(void)
{
	value--;
	return *this;
}

Fixed& Fixed::min(Fixed &l, Fixed &r)
{
	if (l < r)
		return l;
	return r;
}

const Fixed& Fixed::min(const Fixed &l, const Fixed &r)
{
	if (l < r)
		return l;
	return r;
}

Fixed& Fixed::max(Fixed &l, Fixed &r)
{
	if (l > r)
		return l;
	return r;
}

const Fixed& Fixed::max(const Fixed &l, const Fixed &r)
{
	if (l > r)
		return l;
	return r;
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