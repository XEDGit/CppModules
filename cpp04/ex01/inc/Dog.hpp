#ifndef DOG_HPP
# define DOG_HPP

# include <Animal.hpp>
# include <Brain.hpp>

class Dog : public Animal
{
	private:
		std::string type;
		Brain*		brain;

	public:
					Dog(void);
					~Dog();
					Dog(const Dog& old);
		Dog&		operator=(const Dog& old);
		void		makeSound(void) const;
		void		addIdea(std::string idea) const;
		void		displayIdeas() const;
		std::string getType() const;
};

#endif