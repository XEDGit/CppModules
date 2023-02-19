#include <Harl.hpp>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: not enough arguments" << std::endl << "Usage: " << argv[0] << " <filter>" << std::endl;
		return 1;
	}
	Harl harl = Harl(argv[1]);
	for (int i = 0; i < 15; i++)
	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
	harl.complain("NOTEXISTING");
}
