#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <Shared.hpp>

class Brain
{
	private:
		int	index;
		std::string ideas[100];
	public:
				Brain(void);
				~Brain();
				Brain(const Brain& old);
		Brain&	operator=(const Brain& old);
		void	addIdea(std::string idea);
		void	displayIdeas();
};

#endif