#ifndef PRESIDENTIALPARDONAForm_HPP
# define PRESIDENTIALPARDONAForm_HPP

# include <iostream>
# include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
									PresidentialPardonForm(std::string ntarget);
									~PresidentialPardonForm();
									PresidentialPardonForm(const PresidentialPardonForm &old);
		PresidentialPardonForm& 	operator=(const PresidentialPardonForm &old);
		void						beExecuted() const;
};

#endif
