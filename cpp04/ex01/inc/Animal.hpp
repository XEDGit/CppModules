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
		virtual std::string	getType() const;
		virtual void		makeSound(void) const;
		virtual void 		addIdea(std::string idea) const;
		virtual void 		displayIdeas() const;
};

#endif