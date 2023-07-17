#include <BitcoinExchange.hpp>

bool openfile(const char *path, std::ifstream& f)
{
	f.open(path);
	if (!f)
	{
		std::cerr << "Error: file '" << path << "' not found" << std::endl;
		return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <path to input file>" << std::endl;
		return 1;
	}

	std::ifstream input, data;
	bool err = false;

	err = openfile("./data.csv", data);
	if (err)
		return 1;

	err = openfile(argv[1], input);
	if (err)
	{
		data.close();
		return 1;
	}

	BitcoinExchange	b(data);

	std::string	line;
	std::getline(input, line);
	while (std::getline(input, line))
		b.GetPrice(line);
}
