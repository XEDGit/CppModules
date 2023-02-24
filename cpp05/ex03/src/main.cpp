#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main()
{
	Bureaucrat a = Bureaucrat("carlo", 1);
	Bureaucrat b = Bureaucrat("rarlo", 20);
	Bureaucrat c = Bureaucrat("marlo", 150);

	Intern lol = Intern();

	AForm* sform = lol.makeForm("shrubbery creation", "home");
	AForm* rform = lol.makeForm("robotomy request", "home");
	AForm* pform = lol.makeForm("presidential pardon", "home");
	lol.makeForm("a random one", "home");

	a.signForm(*pform);
	b.signForm(*rform);
	c.signForm(*sform);
	for (int i = 0; i < 5; i++)
		c.addGrade();
	c.signForm(*sform);

	a.executeForm(*rform);
	a.executeForm(*rform);
	a.executeForm(*rform);
	a.executeForm(*rform);
	c.executeForm(*pform);
	a.executeForm(*pform);
	a.executeForm(*sform);

	delete (PresidentialPardonForm *)pform;
	delete (ShrubberyCreationForm *)sform;
	delete (RobotomyRequestForm *)rform;
}
