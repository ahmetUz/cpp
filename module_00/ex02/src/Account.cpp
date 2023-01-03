/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:22:26 by auzun             #+#    #+#             */
/*   Updated: 2023/01/03 06:20:43 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	res = std::time(NULL);

	std::cout << std::setfill('0') << "[" << 1900 + std::localtime(&res)->tm_year
	<< std::setw(2) << 1 + std::localtime(&res)->tm_mon
	<< std::setw(2) << std::localtime(&res)->tm_mday << "_"
	<< std::setw(2) << std::localtime(&res)->tm_hour
	<< std::setw(2) << std::localtime(&res)->tm_min
	<< std::setw(2) << std::localtime(&res)->tm_sec << "] ";
}

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
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:"<< getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	_totalNbDeposits++;
	this->_nbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}
