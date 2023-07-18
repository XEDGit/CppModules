#include <RPN.hpp>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}

	std::stack<std::string> a;
	std::string	s = argv[1];
	std::reverse(s.begin(), s.end());

	for (size_t i = s.find_first_not_of(' ', 0); i < s.length();) {
		size_t j = s.find_first_of(' ', i) - i;
		a.push(s.substr(i, j));
		if (j + i == s.npos)
			break;
		i = s.find_first_not_of(' ', i + j);
	}

	try {
		RPN	instance(a);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	
}
