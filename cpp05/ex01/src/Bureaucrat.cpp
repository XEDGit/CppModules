#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(std::string nname, int ngrade) : name(nname), grade(ngrade)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &old) : name(old.name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	grade = old.grade;
	return *this;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

std::string Bureaucrat::getName() const
{
	return name;
}

void Bureaucrat::addGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::subGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat &toPrint)
{
	out << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade();
	return out;
}
