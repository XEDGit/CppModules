#include <RPN.hpp>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "ARGV MSG" << std::endl;
		return 1;
	}

	RPN	instance(argv);
}
