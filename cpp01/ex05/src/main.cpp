#include <Harl.hpp>

int main()
{
	Harl harl = Harl();
	for (int i = 0; i < 15; i++)
	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
	harl.complain("NOTEXISTING");
}
