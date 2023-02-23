#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
						Bureaucrat(std::string nname, int ngrade);
						~Bureaucrat();
						Bureaucrat(const Bureaucrat &old);
		Bureaucrat& 	operator=(const Bureaucrat &old);

		int				getGrade() const;
		std::string		getName() const;

		void			addGrade();
		void			subGrade();
		void			signForm(AForm& form);
		void			executeForm(AForm const & form);

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat &toPrint);

# include <AForm.hpp>

#endif
