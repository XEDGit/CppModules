#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <Animal.hpp>

class Dog : public Animal
{
	private:
		std::string type;

	public:
					Dog(void);
					~Dog();
					Dog(const Dog& old);
		Dog&		operator=(const Dog& old);
		void		makeSound(void) const;
		std::string getType() const;
};

#endif