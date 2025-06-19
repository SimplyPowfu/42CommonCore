/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:43:54 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/19 17:38:03 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : contacts_number(0), size(0) {}

void	Phonebook::addContact()
{
	contacts[contacts_number].setContact();
	contacts_number = (contacts_number + 1) % 8;
	if (size < 8)
		size++;
	
}

void	Phonebook::searchContact()
{
	if (size == 0) {
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < size; i++)
		contacts[i].checkContact(i);
	std::cout << "Contact number: ";
	int index;
	std::cin >> index;
	std::cin.ignore();
	if (std::cin.fail() || index <= 0 || index > size)
	{
		std::cin.clear();
		std::cin.ignore(2147483647, '\n');
		std::cout << "invalid number" << std::endl;
	}
	else
		contacts[index - 1].printContact();
}
