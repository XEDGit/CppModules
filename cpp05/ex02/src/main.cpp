#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main()
{
	Bureaucrat a = Bureaucrat("carlo", 1);
	Bureaucrat b = Bureaucrat("rarlo", 20);
	Bureaucrat c = Bureaucrat("marlo", 150);

	ShrubberyCreationForm sform = ShrubberyCreationForm("home");
	RobotomyRequestForm rform = RobotomyRequestForm("home");
	PresidentialPardonForm pform = PresidentialPardonForm("home");

	a.signForm(pform);
	b.signForm(rform);
	c.signForm(sform);
	for (int i = 0; i < 5; i++)
		c.addGrade();
	c.signForm(sform);

	a.executeForm(rform);
	a.executeForm(rform);
	a.executeForm(rform);
	a.executeForm(rform);
	c.executeForm(pform);
	a.executeForm(pform);
	a.executeForm(sform);
}
