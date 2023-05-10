#include <ScalarConverter.hpp>

int main(int argc, char** argv)
{
	if (argc <= 1)
		return (0); //usage
	ScalarConverter::converter(argv[1]);
}
