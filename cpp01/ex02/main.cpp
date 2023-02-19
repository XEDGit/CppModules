#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string* strptr = &str;
	std::string& strref = str;

	std::cout << "&str:\t" << &str << std::endl << "strptr:\t" << strptr << std::endl << "&strref:" << &strref << std::endl;
	std::cout << "str:\t" << str << std::endl << "*strptr:" << *strptr << std::endl << "strref:" << strref << std::endl;
}
