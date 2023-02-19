#include <PhoneBook.hpp>

PhoneBook::PhoneBook(void)
{
	index = 0;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::add()
{
	Contact toAdd = Contact();
	if (!toAdd.fill())
	{
		std::cout << "Contact fields can't be empty" << std::endl;
		return false;
	}
	if (index == 8)
		index = 0;
	contacts[index] = toAdd;
	index++;
	std::cout << "Contact created" << std::endl;
	return true;
}

void PhoneBook::display()
{
	int 		i;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl << "|----------|----------|----------|----------|" << std::endl;
	for (i = 0; i < 8 && contacts[i].preview(i); i++);
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	if (i == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return;
	}
	std::cout << "Enter index to display or ESC to go back: ";
	int 		c = -1;
	std::string	s;
	while (true)
	{
		std::getline(std::cin, s);
		if (!s.compare("ESC"))
			return;
		c = s[0] - '0';
		if (c >= 0 && c < i)
			break;
		std::cout << "Enter index between 0 and " << i - 1 << " or ESC to go back: ";
	}
	contacts[c].display();
}
