#ifndef SHRUBBERYCREATIONAForm_HPP
# define SHRUBBERYCREATIONAForm_HPP

# include <iostream>
# include <AForm.hpp>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
								ShrubberyCreationForm(std::string ntarget);
								~ShrubberyCreationForm();
								ShrubberyCreationForm(const ShrubberyCreationForm &old);
		ShrubberyCreationForm& 	operator=(const ShrubberyCreationForm &old);
		void					beExecuted() const;
};

#endif
