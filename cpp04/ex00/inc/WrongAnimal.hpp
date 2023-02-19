#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
							WrongAnimal(void);
		virtual				~WrongAnimal();
							WrongAnimal(const WrongAnimal& old);
		WrongAnimal&		operator=(const WrongAnimal& old);
		virtual std::string	getType() const;
		void				makeSound(void) const;
};

#endif