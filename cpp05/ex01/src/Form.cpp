#include <Form.hpp>

Form::Form(std::string nname, int ngradeToExecute, int ngradeToSign) : name(nname), gradeToExecute(ngradeToExecute), gradeToSign(ngradeToSign)
{
	std::cout << "Default constructor called on Form" << std::endl;
	sign = false;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &old) : gradeToExecute(old.gradeToExecute), gradeToSign(old.gradeToSign)
{

	std::cout << "Copy constructor called on Form" << std::endl;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
	*this = old;
}

Form::~Form()
{
	std::cout << "Destructor called on Form" << std::endl;
}

Form	&Form::operator =(const Form &old)
{
	std::cout << "Copy assignment operator called on Form" << std::endl;
	name = old.name;
	sign = old.sign;
	return *this;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

bool Form::isSigned() const
{
	return sign;
}

std::string Form::getName() const
{
	return name;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	sign = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const Form &toPrint)
{
	out << toPrint.getName() << " " << (toPrint.isSigned()? "is" : "is not") << " signed," << " needs grade " << toPrint.getGradeToSign() << " to be signed and grade " << toPrint.getGradeToExecute() << " to execute" << std::endl;
	return out;
}
