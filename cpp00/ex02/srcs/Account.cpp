/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:29:36 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/12 11:16:32 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
# include <iostream>
# include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
	std::cout << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << "index:";
	this->_accountIndex = _nbAccounts;
	std::cout << this->_accountIndex;
	this->_nbAccounts++;
	std::cout << ";amount:";
	this->_amount = initial_deposit;
	std::cout << this->_amount;
	this->_totalAmount += this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ";deposit:";
	std::cout << deposit;
	std::cout << ";amount:";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << this->_amount;
	std::cout << ";nb_deposits:";
	std::cout << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	this->_amount -= withdrawal;
	if (checkAmount())
	{
		this->_amount += withdrawal;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std::cout << ";withdrawal:";
	std::cout << withdrawal;
	std::cout << ";amount:";
	this->_totalAmount -= withdrawal;
	std::cout << this->_amount;
	std::cout << ";nb_withdrawals:";
	std::cout << this->_nbDeposits << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	if (this->_amount < 0)
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
	std::cout << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	// std::cout << "[19920104_091532] ";
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	char output[20];
	strftime(output, 20, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}
