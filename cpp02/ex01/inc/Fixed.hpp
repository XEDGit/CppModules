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

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &toPrint);

#endif
