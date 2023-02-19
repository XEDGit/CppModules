#include <NewSed.hpp>

NewSed::NewSed(std::string out) : input(out), output(out + ".replace")
{
}

NewSed::~NewSed()
{
}

bool NewSed::replace(std::string toReplace, std::string newString)
{
	std::ifstream in(input);

	if (!in.is_open())
	{
		std::cerr << "Error opening input file" << std::endl;
		return false;
	}
	std::ofstream out(output);
	if (!out.is_open())
	{
		in.close();
		std::cerr << "Error opening output file" << std::endl;
		return false;
	}
	std::string content;
	std::getline(in, content, '\0');
	size_t found, eraselen = toReplace.length();
	while ((found = content.find(toReplace)) < content.length())
	{
		content.erase(found, eraselen);
		content.insert(found, newString);
	}
	out << content;
	return true;
}
