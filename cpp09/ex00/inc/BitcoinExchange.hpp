#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <filesystem>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	db;
	public:
							BitcoinExchange(std::ifstream& f);
							~BitcoinExchange();
							BitcoinExchange(const BitcoinExchange &old);
		BitcoinExchange& 	operator=(const BitcoinExchange &old);
		void				AddToDb(std::string& line);
		void				GetPrice(std::string& line);
};

#endif
