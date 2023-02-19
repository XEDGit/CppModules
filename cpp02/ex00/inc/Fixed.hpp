#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	fractionalBits = 8;
public:
			Fixed(void);
			Fixed(const Fixed &old);
			Fixed& operator=(const Fixed &old);
			~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif
