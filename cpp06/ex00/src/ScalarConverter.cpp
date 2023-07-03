#include <ScalarConverter.hpp>

static int scStoi(std::string str)
{
	return std::stoi(str);
}

static double scStod(std::string str)
{
	return std::stod(str);
}

static float scStof(std::string str)
{
	return std::stof(str);
}

ScalarConverter::ScalarConverter(std::string& str)
{
	type = check_type(str);
	possible = true;

	switch (type)
	{
		case Int:
			possible = tryConversion(str, scStoi, &in);
			fl = static_cast<float>(in);
			dl = static_cast<double>(in);
			ch = static_cast<char>(in);
			break;
		case Float:
			possible = tryConversion(str, scStof, &fl);
			dl = static_cast<double>(fl);
			in = static_cast<int>(fl);
			ch = static_cast<char>(fl);
			break;
		case Char:
			ch = str[0];
			dl = static_cast<double>(ch);
			fl = static_cast<float>(ch);
			in = static_cast<int>(ch);
			break;
		case Double:
			possible = tryConversion(str, scStod, &dl);
			fl = static_cast<float>(dl);
			in = static_cast<int>(dl);
			ch = static_cast<char>(dl);
			break;
	}
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
	ch = old.ch;
	in = old.in;
	fl = old.fl;
	dl = old.dl;
	type = old.type;
	possible = old.possible;
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

types ScalarConverter::check_type(std::string &str)
{
	unsigned long i = 0;

	while (str[i] == ' ' && i + 1 != str.length())
		str.erase(0, 1);
	if (find_substr(str, "nan", i, 3))
	{
		if (str[i + 3] == 'f' && !str[i + 4])
			return Float;
		else if (!str[i + 3])
			return Double;
		else
			return Char;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (find_substr(str, "inf", i, 3))
	{
		if (str[i + 3] == 'f' && !str[i + 4])
			return Float;
		else if (!str[i + 3])
			return Double;
		else
			return Char;
	}
	if (!str[i])
		return Char;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1])
		i++;
	if (!str[i])
		return Int;
	else if (!std::isdigit(str[i]))
		return Char;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == 'f' && !str[i + 1])
		return Float;
	else if (!str[i])
		return Double;
	else
		return Char;
}

void ScalarConverter::converter(std::string str)
{
	ScalarConverter	sc(str);

	float inf = std::numeric_limits<float>::infinity();
	std::cout << "ch: ";
	if (!sc.possible || sc.in > 255 || sc.in < 0 || sc.fl == inf || sc.fl == -inf || sc.fl != sc.fl)
		std::cout << "Impossible" << std::endl;
	else if (std::isprint(sc.ch))
		std::cout << "'" << sc.ch << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (!sc.possible || (sc.type != Char && !sc.tryConversion(str, scStoi, (int *)0)))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << sc.in << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1);
	if (!sc.possible || (sc.type != Char && !sc.tryConversion(str, scStof, (float *)0)))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << sc.fl << "f" << std::endl;
	std::cout << "double: ";
	if (!sc.possible || (sc.type != Char && !sc.tryConversion(str, scStod, (double *)0)))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << sc.dl << std::endl;
}
