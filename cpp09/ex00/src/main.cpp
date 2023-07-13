#include <BitcoinExchange.hpp>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./" << argv[0] << "<path to input file>" << std::endl;
		return 1;
	}
	std::string		path = argv[1];
	if (path.length() < 4 || path.compare(path.length() - 4, 4, ".csv"))
	{
		std::cerr << "Error: '" << path << "' must end in '.csv'" << std::endl;
		return 1;
	}
	std::ifstream	f;

	f.open(path);
	if (!f)
	{
		std::cerr << "Error: file '" << path << "' not found" << std::endl;
		return 1;
	}
	BitcoinExchange	b(f);

}
