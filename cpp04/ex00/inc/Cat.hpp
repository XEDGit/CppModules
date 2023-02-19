#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <Animal.hpp>

class Cat : public Animal
{
	private:
		std::string type;

	public:
					Cat(void);
					~Cat();
					Cat(const Cat& old);
		Cat&		operator=(const Cat& old);
		void		makeSound(void) const;
		std::string getType() const;
};

#endif