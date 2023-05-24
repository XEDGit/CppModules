#include <ScalarConverter.hpp>

int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cout << "usage: " << argv[0] << " <numeric value>" << std::endl;
		return (1);
	}
	ScalarConverter::converter(argv[1]);
}
