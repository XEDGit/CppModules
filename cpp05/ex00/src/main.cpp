#include <Bureaucrat.hpp>

int main(void)
{
	Bureaucrat lol = Bureaucrat("lol", 1);
	Bureaucrat ror = Bureaucrat("ror", 150);

	try
	{
		lol.addGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	try
	{
		ror.subGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << lol << std::endl << ror << std::endl;
	lol.subGrade();
	ror.addGrade();
	std::cout << lol << std::endl << ror << std::endl;
}
