#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
		int				getGrade();
		std::string		getName();
		void			addGrade();
		void			subGrade();

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
