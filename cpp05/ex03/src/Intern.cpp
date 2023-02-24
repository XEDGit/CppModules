#include <Intern.hpp>

Intern::Intern(void)
{
	std::cout << "Default constructor called on Intern" << std::endl;
}

Intern::Intern(const Intern &old)
{

	std::cout << "Copy constructor called on Intern" << std::endl;
	*this = old;
}

Intern::~Intern()
{
	std::cout << "Destructor called on Intern" << std::endl;
}

Intern	&Intern::operator =(const Intern &old)
{

	std::cout << "Copy assignment operator called on Intern" << std::endl;
	(void)old;
	return *this;
}

static int	compareName(std::string name)
{
	std::string	names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int i;
	for (i = 0; i < 3 && names[i].compare(name); i++);
	return i;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *ret;

	switch (compareName(name))
	{
	case 0:
		ret = new RobotomyRequestForm(target);
		break;

	case 1:
		ret = new ShrubberyCreationForm(target);
		break;

	case 2:
		ret = new PresidentialPardonForm(target);
		break;
	
	default:
		std::cerr << "Your intern is complaining: There's no form called " << name << std::endl;
		return NULL;
	}
	return ret;
}
