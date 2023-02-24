#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <AForm.hpp>
# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <PresidentialPardonForm.hpp>

class Intern
{
	private:
	public:
					Intern(void);
					~Intern();
					Intern(const Intern &old);
		Intern& 	operator=(const Intern &old);
		AForm*		makeForm(std::string name, std::string target);
};

#endif
