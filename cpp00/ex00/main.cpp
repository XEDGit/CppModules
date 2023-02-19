#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 1; i != argc; i++)
		for (int ch = 0; argv[i][ch] != '\0'; ch++)
			std::cout << (char)toupper(argv[i][ch]);
	if (argc == 1) std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}