#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
	private:
		std::string type;

	public:
					WrongCat(void);
					~WrongCat();
					WrongCat(const WrongCat& old);
		WrongCat&	operator=(const WrongCat& old);
		std::string getType() const;
};

#endif