#include <Form.hpp>

int main()
{
	Bureaucrat a = Bureaucrat("carlo", 1);
	Bureaucrat b = Bureaucrat("rarlo", 20);
	Bureaucrat c = Bureaucrat("marlo", 150);

	Form form = Form("strong form", 19, 1);

	a.signForm(form);
	b.signForm(form);
	c.signForm(form);
}
