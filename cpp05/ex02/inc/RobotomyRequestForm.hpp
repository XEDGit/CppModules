#ifndef ROBOTOMYREQUESTAForm_HPP
# define ROBOTOMYREQUESTAForm_HPP

# include <iostream>
# include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
								RobotomyRequestForm(std::string ntarget);
								~RobotomyRequestForm();
								RobotomyRequestForm(const RobotomyRequestForm &old);
		RobotomyRequestForm& 	operator=(const RobotomyRequestForm &old);
		void					beExecuted() const;
};

#endif
