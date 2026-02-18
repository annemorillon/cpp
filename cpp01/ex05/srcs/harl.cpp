#include "harl.hpp"

void	Harl::complain(std::string level)
{
	_ptrfunction[0] = &Harl::debug;
	_ptrfunction[1] = &Harl::info;
	_ptrfunction[2] = &Harl::warning;
	_ptrfunction[3] = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "message DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "message INFO" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "message WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "message ERROR" << std::endl;
}