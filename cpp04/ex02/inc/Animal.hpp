#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <Shared.hpp>

class Animal
{
	protected:
		std::string type;

	public:
							Animal(void);
		virtual				~Animal();
							Animal(const Animal& old);
		Animal&				operator=(const Animal& old);
		virtual std::string	getType() const = 0;
		virtual void		makeSound(void) const = 0;
		virtual void 		addIdea(std::string idea) const = 0;
		virtual void 		displayIdeas() const = 0;
};

#endif