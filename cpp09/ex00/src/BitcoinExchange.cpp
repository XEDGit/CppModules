#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(std::ifstream& f)
{
	std::string	line;

	std::getline(f, line);
	while (std::getline(f, line))
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
	std::map<int, double>::const_iterator it = old.db.begin();

	while (it != old.db.end())
		db[it->first] = double(it->second);
	return *this;
}

void BitcoinExchange::AddToDb(std::string &line)
{
	std::string l = line;
	l.erase(std::remove(l.begin(), l.end(), '-'), l.end());
	try {
		int key = std::stoi(l);
		db[key] = std::stod(l.substr(l.find(',') + 1));
	}
	catch(const std::exception& e) {
		std::cerr << "Error on line '" << line << "': " << e.what() << '\n';
	}
	
}

static bool hasvalue(std::string &l)
{
	size_t i = l.find('|') + 1;
	while (l[i] == ' ')
		i++;
	if (l[i] == '-')
		i++;
	if (!std::isdigit(l[i]))
		return false;
	return true;
}

void BitcoinExchange::GetPrice(std::string &line)
{
	try {
		std::string l = line;
		l.erase(std::remove(l.begin(), l.end(), ' '), l.end());
		size_t div = l.find('|');
		if (div == l.npos || div == 0)
			throw std::logic_error("bad format => " + line);
		l.erase(std::remove(l.begin(), l.begin() + div, '-'), l.begin() + div);
		div = l.find('|');
		if (div == l.size() - 1)
			throw std::logic_error("bad format => " + line);
		for (size_t i = 0; i < div; i++)
			if (!std::isdigit(l[i]))
				throw std::logic_error("bad format => " + line);
		int key = std::stoi(l);
		bool dot = false;
		int min = l[div + 1] == '-';
		if (min)
			min = 2;
		else
			min = 1;
		for (size_t i = div + min ; i < l.size(); i++) {
			if (!(std::isdigit(l[i]) || (l[i] == '.' && !dot)))
				throw std::logic_error("bad format => " + line);
			if (l[i] == '.' && !dot)
					dot = true;
		}
		double amount = std::stod(l.substr(div + 1));
		if ((key / 100) % 100 > 12 || (key / 100) % 100 == 0 || key % 100 > 31 || key % 100 == 0 || !hasvalue(l))
			throw std::logic_error("bad format => " + line);
		if (amount > 1000)
			throw std::out_of_range("too large a number");
		else if (amount < 0)
			throw std::out_of_range("not a positive number");
		std::map<int, double>::iterator high = db.lower_bound(key), low;
		if (high == db.begin() && key != (*high).first)
			throw std::out_of_range("date is before first database entry");
		if (high == db.begin())
			low = high;
		else
			low = std::prev(high);
		double value = (*low).second * amount;
		std::cout << line.substr(0, line.find('|') - 1) << " => " << amount << " = " << value << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << "." << std::endl;
	}
}
