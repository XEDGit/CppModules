#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <filesystem>
# include <algorithm>
# include <string>

class BitcoinExchange
{
	private:
		std::map<int, double>	db;
	public:
							BitcoinExchange(std::ifstream& f);
							~BitcoinExchange();
							BitcoinExchange(const BitcoinExchange &old);
		BitcoinExchange& 	operator=(const BitcoinExchange &old);
		void				AddToDb(std::string& line);
		void				GetPrice(std::string& line);
};

#endif
