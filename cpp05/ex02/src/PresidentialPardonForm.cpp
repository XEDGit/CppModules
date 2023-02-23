#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(std::string ntarget) : AForm("Presidential Pardon Form", 5, 25)
{
	std::cout << "Default constructor called on PresidentialPardonForm" << std::endl;
	target = ntarget;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old) : AForm("Presidential Pardon Form", 5, 25)
{
	std::cout << "Copy constructor called on PresidentialPardonForm" << std::endl;
	*this = old;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called on PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator =(const PresidentialPardonForm &old)
{
	target = old.target;
	std::cout << "Copy assignment operator called on PresidentialPardonForm" << std::endl;
	return *this;
}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << "lol" << std::endl;
}
