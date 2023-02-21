#ifndef CAT_HPP
# define CAT_HPP

# include <Animal.hpp>
# include <Brain.hpp>

class Cat : public Animal
{
	private:
		std::string type;
		Brain*		brain;

	public:
					Cat(void);
					~Cat();
					Cat(const Cat& old);
		Cat&		operator=(const Cat& old);
		void		makeSound(void) const;
		void		addIdea(std::string idea) const;
		void		displayIdeas() const;
		std::string getType() const;
};

#endif