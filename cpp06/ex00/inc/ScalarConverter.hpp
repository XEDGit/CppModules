#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <limits>

enum types {
	Char,
	Int,
	Float,
	Double,
};

static int		scStoi(std::string str);
static double	scStod(std::string str);
static float	scStof(std::string str);

class ScalarConverter
{
	private:
		int					in;
		double				dl;
		float				fl;
		char				ch;
		bool				possible;
		types				type;
							ScalarConverter(std::string& str);
							~ScalarConverter();
							ScalarConverter(const ScalarConverter& old);
		ScalarConverter& 	operator=(const ScalarConverter& old);
		types				check_type(std::string& str);
		template <typename T>
		bool				tryConversion(std::string& str, T (*func)(std::string), T* val)
		{
			try
			{
				if (val)
					*val = func(str);
				else
					func(str);
				return true;
			}
			catch(const std::exception& e)
			{
				return false;
			}
		}

	public:
		static void			converter(std::string str);
};

#endif
