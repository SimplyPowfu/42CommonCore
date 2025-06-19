/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:53:14 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/19 18:06:34 by ecarbona         ###   ########.fr       */
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