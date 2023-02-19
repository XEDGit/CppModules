#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <vector>

class Harl
{
private:
	int			filter;
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
	void		(Harl::*funcs[4])(void);
public:
				Harl(std::string);
				~Harl();
	void		complain(std::string level);
};

#endif
