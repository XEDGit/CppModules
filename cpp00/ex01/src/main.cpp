#include <PhoneBook.hpp>

int main()
{
	std::cout << "Welcome to your favourite Phonebook!" << std::endl;
	PhoneBook	phonebook = PhoneBook();
	std::string choice;
	while (1)
	{
		choice = "";
		std::cout << "What do you want to do?" << std::endl;
		std::getline(std::cin, choice);
		if (!choice.compare("ADD"))
			phonebook.add();
		else if (!choice.compare("SEARCH"))
			phonebook.display();
		else if (!choice.compare("EXIT"))
			break;
		else
			std::cout << "\"" << choice << "\" is not a command, you can use ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "Goodbye :)" << std::endl;
}