#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template <typename T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	private:
		typedef std::stack<T, C> stack;
	public:
		MutantStack() {};
		~MutantStack() {};

		// MutantStack(const MutantStack &old) {
		// 	*this = old;
		// };

		// MutantStack&	operator=(const MutantStack &old) {
		// 	stack::operator=(old);
		// 	return *this;
		// };

		typedef typename C::iterator iterator;

		iterator	begin(void) {
			return this->c.begin();
		}

		iterator	end(void) {
			return this->c.end();
		}
};

#endif
