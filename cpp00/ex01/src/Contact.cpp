#include <Contact.hpp>

Contact::Contact(void) 
{
	name.clear();
	surname.clear();
	nickname.clear();
	number.clear();
}

Contact::~Contact(void)
{
}

int	Contact::fill()
{
	std::cout << "Insert first name:" << std::endl;
	std::getline(std::cin, name);
	std::cout << "Insert last name:" << std::endl;
	std::getline(std::cin, surname);
	std::cout << "Insert nickname:" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Insert phone number:" << std::endl;
	std::getline(std::cin, number);
	std::cout << "Insert darkest secret:" << std::endl;
	std::getline(std::cin, secret);
	if (name.empty() || surname.empty() || nickname.empty() || number.empty() || secret.empty())
		return false;
	return true;
}

bool Contact::preview(int index)
{
	if (name.empty())
		return false;
	std::cout << "|" << std::right << std::setw(10) << index << \
				 "|" << std::right << std::setw(10) << name.substr(0, 10) << \
				 "|" << std::right << std::setw(10) << surname.substr(0, 10) << \
				 "|" << std::right << std::setw(10) << nickname.substr(0, 10) << \
				 "|" << std::endl;
	return true;
}

void Contact::display()
{
	std::cout << std::endl << "First name:\t" << name << std::endl << "Last name:\t" << surname << std::endl << "Nickname:\t" << nickname << std::endl << "Number:\t\t" << number << std::endl << "Darkest secret:\t" << secret << std::endl << std::endl;
}