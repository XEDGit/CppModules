#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	private:
		std::string	name;
		std::string	surname;
		std::string	nickname;
		std::string	number;
		std::string	secret;
	public:
				Contact(void);
				~Contact(void);
		int		fill();
		void	display();
		bool	preview(int index);
};

#endif