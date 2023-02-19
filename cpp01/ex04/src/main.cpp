#include <NewSed.hpp>

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cout << "Error: Not enough arguments" << std::endl << "Usage: ./" << argv[0] << " <filename> <string to replace> <replacee>" << std::endl;
		return 1;
	}
	NewSed sed = NewSed(argv[1]);
	sed.replace(argv[2], argv[3]);
}
