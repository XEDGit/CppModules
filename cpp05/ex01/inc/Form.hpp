#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
class Bureaucrat;

class Form
{
	private:
		std::string	name;
		bool		sign;
		const int	gradeToExecute;
		const int	gradeToSign;
	public:
					Form(std::string nname, int ngradeToExecute, int ngradeToSign);
					~Form();
					Form(const Form &old);
		Form& 		operator=(const Form &old);

		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		isSigned() const;
		std::string	getName() const;

		void		beSigned(Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Form &toPrint);

# include <Bureaucrat.hpp>
#endif
