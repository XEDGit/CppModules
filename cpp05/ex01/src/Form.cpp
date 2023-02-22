#include <Form.hpp>

Form::Form(void)
{
	std::cout << "Default constructor called on Form" << std::endl;
}

Form::Form(const Form &old)
{

	std::cout << "Copy constructor called on Form" << std::endl;
	*this = old;
}

Form::~Form()
{
	std::cout << "Destructor called on Form" << std::endl;
}

Form	&Form::operator =(const Form &old)
{

	std::cout << "Copy assignment operator called on Form" << std::endl;
	// TODO
	return *this;
}
