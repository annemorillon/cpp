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
	std::cout << _displayTimestamp() << std::endl;
	std::cout << "accounts:";
	std::cout << this->_nbAccounts;
	std::cout << ";total:"
	std::cout << this->_totalAmount;
	std::cout << ";deposits:"
	std::cout << this->_totalNbDeposits;
	std::cout << ";withdrawals:"
	std::cout << this->_totalNbWithdrawals;
}

// a completer //

Account::Account(int initial_deposit)
{
	std::cout << _displayTimestamp();
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
	std::cout << _displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";closed";
}

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int		Account::checkAmount( void ) const
{
	
}

void	Account::displayStatus( void ) const
{
	std::cout << _displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";deposits:";
	std::cout << this->_nbDeposits;
	std::cout << ";withdrawals:";
	std::cout << this->_nbWithdrawals;
}

static void	Account::_displayTimestamp( void )
{

}

Account::Account( void )
{
	
}