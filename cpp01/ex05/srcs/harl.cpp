#include "../includes/harl.hpp"

Harl::Harl(void)
{
	_ptrfunction[0] = &Harl::debug;
	_ptrfunction[1] = &Harl::info;
	_ptrfunction[2] = &Harl::warning;
	_ptrfunction[3] = &Harl::error;
	_ptrfunction[4] = &Harl::wrong;
}

Harl::~Harl()
{
}

void	Harl::complain(std::string	level)
{
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && level != tab[i])
		i++;

	(this->*_ptrfunction[i])();
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::wrong(void)
{
	std::cout << "Wrong input" << std::endl;
}