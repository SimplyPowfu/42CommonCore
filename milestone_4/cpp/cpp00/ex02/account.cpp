/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:53:14 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/25 19:10:39 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//OPERAZIONI DA FARE;
//aprire e chiudere il conto;
//stampare l'estratto conto;
//eseguire un deposito;
//eseguire un ritiro;
//tutto va stampato nella stessa forma con il time stamp davanti

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cctype>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t time = std::time(NULL);
	std::tm* localTime = std::localtime(&time);
	std::cout	<< "["
				<< std::setfill('0') << std::setw(4) << localTime->tm_year + 1900
				<< std::setw(2) << localTime->tm_mon + 1
				<< std::setw(2) << localTime->tm_mday << "_"
				<< std::setw(2) << localTime->tm_hour
				<< std::setw(2) << localTime->tm_min
				<< std::setw(2) << localTime->tm_sec << "] "; 
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount = _amount + deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount = _amount - withdrawal;
	_nbWithdrawals++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
    _nbAccounts--;
}