#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <Contact.hpp>

class PhoneBook {
	private:
		Contact contacts[8];
		int		index;
	public:
		PhoneBook(void);
		~PhoneBook();
		int		add();
		void	display();
};

#endif