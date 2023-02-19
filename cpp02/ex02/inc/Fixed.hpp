#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	static const int	fractionalBits = 8;
public:
			Fixed(void);
			Fixed(int nvalue);
			Fixed(float nvalue);
			Fixed(const Fixed &old);
			~Fixed();

	Fixed& 	operator=(const Fixed &old);
	bool	operator<(const Fixed &r) const;
	bool	operator>(const Fixed &r) const;
	bool	operator!=(const Fixed &r) const;
	bool	operator==(const Fixed &r) const;
	bool	operator<=(const Fixed &r) const;
	bool	operator>=(const Fixed &r) const;

	Fixed	operator+(const Fixed &r) const;
	Fixed	operator-(const Fixed &r) const;
	Fixed	operator*(const Fixed &r) const;
	Fixed	operator/(const Fixed &r) const;

	Fixed	operator++(int i);
	Fixed	operator--(int i);
	Fixed&	operator++(void);
	Fixed&	operator--(void);

	static Fixed& min(Fixed &l, Fixed &r);
	static const Fixed& min(const Fixed &l, const Fixed &r);
	static Fixed& max(Fixed &l, Fixed &r);
	static const Fixed& max(const Fixed &l, const Fixed &r);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &toPrint);

#endif
