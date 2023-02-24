#include <ShrubberyCreationForm.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string ntarget) : AForm("Shrubbery Creation Form", 137, 145)
{
	std::cout << "Default constructor called on ShrubberyCreationForm" << std::endl;
	target = ntarget;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old) : AForm("Shrubbery Creation Form", 137, 145)
{

	std::cout << "Copy constructor called on ShrubberyCreationForm" << std::endl;
	*this = old;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called on ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator =(const ShrubberyCreationForm &old)
{

	target = old.target;
	std::cout << "Copy assignment operator called on ShrubberyCreationForm" << std::endl;
	return *this;
}

void ShrubberyCreationForm::beExecuted() const
{
	std::string file_path = target + "_shrubbery";
	std::ofstream fd(file_path);

	if (!fd.is_open())
	{
		std::cerr << "Error opening output file" << std::endl;
		return;
	}

	fd << "            .        +          .      .          ." << std::endl << \
	"     .            _        .                    ." << std::endl << \
	"  ,              /;-._,-.____        ,-----.__" << std::endl << \
	" ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl << \
	"  `                 \\   _|` =:_::.`.);  \\ __/ /" << std::endl << \
	"                      ,    `./  \\:. `.   )==-'  ." << std::endl << \
	"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl << \
	".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl << \
	"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl << \
	"  .      ,=':  \\    ` `/` ' , , ,:' `'-- .-- ---._/`7" << std::endl << \
	"   `.   (    \\: \\,-._` ` + '\\, ,    _,--._,--- :.__/" << std::endl << \
	"              \\:  `  X` _| _,\\/'   .-'" << std::endl << \
	".                :._:`\\____  /:'  /      .           ." << std::endl << \
	"                    \\::.  :\\/:'  /              +" << std::endl << \
	"   .                 `.:.  /:'  }      ." << std::endl << \
	"           .           ):_(:;   \\           ." << std::endl << \
	"                      /:. _/ ,  |" << std::endl << \
	"                   . (|::.     ,`                  ." << std::endl << \
	"     .                |::.    { " << std::endl << \
	"                      |::.\\  \\ `." << std::endl << \
	"                      |:::(\\    |" << std::endl << \
	"                      |:::/{ }  |   " << std::endl << \
	"                  ___/#\\::`/ (O  ==._____" << std::endl;
	fd.close();
}
