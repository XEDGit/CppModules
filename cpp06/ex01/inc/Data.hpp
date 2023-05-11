#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		std::string name;
	public:
				Data(std::string& name);
				~Data();
				Data(const Data &old);
		Data& 	operator=(const Data &old);
};


#endif
