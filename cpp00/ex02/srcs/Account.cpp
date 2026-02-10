/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:29:36 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/06 11:50:31 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
# include <iostream>
# include <ctime>

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) 
{
	_displayTimestamp();
	std::cout << "accounts:";
	std::cout << _nbAccounts;
	std::cout << ";total:";
	std::cout << _totalAmount;
	std::cout << ";deposits:";
	std::cout << _totalNbDeposits;
	std::cout << ";withdrawals:";
	std::cout << _totalNbWithdrawals;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << initial_deposit;
	std::cout << ";created";
	// ajouter le initial deposit
	// update de l'index ?
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";closed";
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits = deposit;
	this->_amount = ;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_nbWithdrawals = withdrawal;
	if (checkAmount())
	{
		this->_nbWithdrawals = 0;
		return (false);
	}
	this->_totalNbWithdrawals++;
	this->_totalAmount -= this->_nbWithdrawals;
	// std::cout << "index:";
	// std::cout << this->_accountIndex;
	// std::cout << ";p_amount:";
	// std::cout << this->_totalAmount;
	// std::cout << ";deposits:";
	// std::cout << this->_nbDeposits;
	// std::cout << ";withdrawals:";
	// std::cout << this->_nbWithdrawals;
	return (true);
}

int		Account::checkAmount( void ) const
{
	if (this->_nbWithdrawals > this->_totalAmount)
		return (1);
	return (0);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";deposits:";
	std::cout << this->_nbDeposits;
	std::cout << ";withdrawals:";
	std::cout << this->_nbWithdrawals;
}

void	Account::_displayTimestamp( void )
{
	struct tm datetime;
	time_t timestamp;

	datetime.tm_year = 1992; // Number of years since 1900
	datetime.tm_mon = 01; // Number of months since January
	datetime.tm_mday = 04;
	datetime.tm_hour = 9;
	datetime.tm_min = 15;
	datetime.tm_sec = 32;
	// Daylight Savings must be specified
	// -1 uses the computer's timezone setting
	datetime.tm_isdst = -1;

	timestamp = mktime(&datetime);

	std::cout << "[" << ctime(&timestamp) << "]" << std::endl;

}

Account::Account( void )
{
	
}