/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:24:07 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/14 15:55:06 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t		timestamp;
	char		output[50];
	struct tm	*datetime;

	time(&timestamp);
	datetime = localtime(&timestamp);
	strftime(output, 50, "[%Y%m%d_%H%M%S] ", datetime);
	std::cout << output;
}

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << " " <<  std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	if (deposit != 0)
		this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount + deposit
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
	if (deposit != 0)
	{
		Account::_totalNbDeposits++;
		this->_amount += deposit;
		Account::_totalAmount += deposit;
	}
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

// returns const value
int Account::checkAmount() const
{
	return 0;
}

// index - amount - deposits - withdrawals
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:"
	<< this->_accountIndex << ";amount:"
	<< this->_amount << ";deposits:"
	<< this->_nbDeposits << ";withdrawls:"
	<< this->_nbWithdrawals << std::endl;
}