#include <Harl.hpp>

Harl::Harl(std::string nfilter)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4 && nfilter.compare(levels[i]); i++);
	filter = i;
	if (filter == 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4 && level.compare(levels[i]); i++);
	if (i < 4 && filter <= i)
		(this->*funcs[i])();
}

void		Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void		Harl::info(void)
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void		Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void		Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}