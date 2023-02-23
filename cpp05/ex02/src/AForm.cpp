#include <AForm.hpp>

AForm::AForm(std::string nname, int ngradeToExecute, int ngradeToSign) : name(nname), gradeToExecute(ngradeToExecute), gradeToSign(ngradeToSign)
{
	std::cout << "Default constructor called on AForm" << std::endl;
	sign = false;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &old) : gradeToExecute(old.gradeToExecute), gradeToSign(old.gradeToSign)
{

	std::cout << "Copy constructor called on AForm" << std::endl;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException();
	*this = old;
}

AForm::~AForm()
{
	std::cout << "Destructor called on AForm" << std::endl;
}

AForm	&AForm::operator =(const AForm &old)
{
	std::cout << "Copy assignment operator called on AForm" << std::endl;
	name = old.name;
	sign = old.sign;
	return *this;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

bool AForm::isSigned() const
{
	return sign;
}

std::string AForm::getName() const
{
	return name;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	sign = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	this->beExecuted();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const AForm &toPrint)
{
	out << toPrint.getName() << " " << (toPrint.isSigned()? "is" : "is not") << " signed," << " needs grade " << toPrint.getGradeToSign() << " to be signed and grade " << toPrint.getGradeToExecute() << " to execute" << std::endl;
	return out;
}
