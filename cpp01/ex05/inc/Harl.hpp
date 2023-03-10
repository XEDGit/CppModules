#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <vector>

class Harl
{
private:
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
	void		(Harl::*funcs[4])(void);
public:
				Harl(void);
				~Harl();
	void		complain(std::string level);
};

#endif
