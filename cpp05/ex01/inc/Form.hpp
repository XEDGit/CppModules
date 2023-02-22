#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form
{
	private:
	public:
				Form(void);
				~Form();
				Form(const Form &old);
		Form& 	operator=(const Form &old);
};

#endif
