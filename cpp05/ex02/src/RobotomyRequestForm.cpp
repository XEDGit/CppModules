#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(std::string ntarget) : AForm("Robotomy Request Form", 45, 72)
{
	std::cout << "Default constructor called on RobotomyRequestForm" << std::endl;
	target = ntarget;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old) : AForm("Robotomy Request Form", 45, 72)
{

	std::cout << "Copy constructor called on RobotomyRequestForm" << std::endl;
	*this = old;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called on RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator =(const RobotomyRequestForm &old)
{
	target = old.target;
	std::cout << "Copy assignment operator called on RobotomyRequestForm" << std::endl;
	return *this;
}

void RobotomyRequestForm::beExecuted() const
{

}
