#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(std::ifstream& f)
{
	std::string	line;
	while ((line = f.getline()))
		AddToDb(line);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &old)
{
	*this = old;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange	&BitcoinExchange::operator =(const BitcoinExchange &old)
{
	std::map<int, double>::const_iterator it = old.db.cbegin();

	while (it != old.db.cend())
		db[it->first] = double(it->second);
	return *this;
}

void BitcoinExchange::AddToDb(std::string &line)
{
	
}

void BitcoinExchange::GetPrice(std::string &line)
{
	(void)line;
}
