#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter(std::string str)
{
	type = check_type(str);
}

ScalarConverter::ScalarConverter(const ScalarConverter &old)
{
	*this = old;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator =(const ScalarConverter &old)
{
	(void) old;
	return *this;
}

static bool	find_substr(std::string& str1, const char* str2, int start, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (str1[start + i] != str2[i])
			return false;
	}
	return true;
}

int scStoi(std::string str)
{
	return std::stoi(str);
}

double scStod(std::string str)
{
	return std::stod(str);
}

float scStof(std::string str)
{
	return std::stof(str);
}

types ScalarConverter::check_type(std::string &str)
{
	unsigned long i = 0;

	while (str[i] == ' ' && i + 1 != str.length())
		str.erase(0, 1);
	if (find_substr(str, "nan", i, 3))
	{
		if (str[i + 3] == 'f')
				return Float;
			else
				return Double;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (find_substr(str, "inf", i, 3))
	{
		if (str[i + 3] == 'f')
			return Float;
		else
			return Double;
	}
	if (!std::isdigit(str[i]))
		return Char;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	else if (!std::isdigit(str[i]))
		return Int;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == 'f')
		return Float;
	else
		return Double;
}

void ScalarConverter::converter(std::string str)
{
	ScalarConverter	sc(str);
	bool			possible = false;

	switch (sc.type)
	{
		case Int:
			possible = sc.tryConversion(str, scStoi, sc.in);
			sc.fl = static_cast<float>(sc.in);
			sc.dl = static_cast<double>(sc.in);
			sc.ch = static_cast<char>(sc.in);
			break;
		case Float:
			possible = sc.tryConversion(str, scStof, sc.fl);
			sc.dl = static_cast<double>(sc.fl);
			sc.in = static_cast<int>(sc.fl);
			sc.ch = static_cast<char>(sc.fl);
			break;
		case Char:
			sc.ch = str[0];
			sc.dl = static_cast<double>(sc.ch);
			sc.fl = static_cast<float>(sc.ch);
			sc.in = static_cast<int>(sc.ch);
			break;
		case Double:
			possible = sc.tryConversion(str, scStod, sc.dl);
			sc.fl = static_cast<float>(sc.dl);
			sc.in = static_cast<int>(sc.dl);
			sc.ch = static_cast<char>(sc.dl);
			break;
	}

	std::cout << "ch: ";
	if (!possible || !sc.tryConversion(str, scStoi, sc.in))
		std::cout << "Impossible" << std::endl;
	else if (std::isprint(sc.ch))
		std::cout << "'" << sc.ch << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (!possible || !sc.tryConversion(str, scStoi, sc.in))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << sc.in << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1);
	if (!possible || !sc.tryConversion(str, scStof, sc.fl))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << sc.fl << "f" << std::endl;
	std::cout << "double: ";
	if (!possible || !sc.tryConversion(str, scStod, sc.dl))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << sc.dl << std::endl;
}
