/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:06:05 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/18 20:09:04 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::setContact()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	if ((firstName == "" || lastName == "" || phoneNumber == "") && !std::cin.eof())
	{
		std::cout << "all field must be filled!" << std::endl;
		setContact();
	}
}
