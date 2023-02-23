#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string	name;
		bool		sign;
		const int	gradeToExecute;
		const int	gradeToSign;

	public:
						AForm(std::string nname, int ngradeToExecute, int ngradeToSign);
						~AForm();
						AForm(const AForm &old);
		AForm& 			operator=(const AForm &old);

		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		bool			isSigned() const;
		std::string		getName() const;

		void			beSigned(Bureaucrat& bureaucrat);
		virtual void	beExecuted() const = 0;
		void			execute(Bureaucrat const & executor) const;

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& toPrint);

# include <Bureaucrat.hpp>

#endif
