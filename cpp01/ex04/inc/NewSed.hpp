#ifndef NEWSED_HPP
# define NEWSED_HPP

# include <fstream>
# include <iostream>

class NewSed
{
private:
	std::string	input;
	std::string	output;
public:
			NewSed(std::string out);
			~NewSed();
	bool	replace(std::string toReplace, std::string newString);
};

#endif
