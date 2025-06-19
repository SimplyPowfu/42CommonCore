/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:19:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/19 17:36:20 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	Phonebook phonebook;
	std::string command;

	while(1)
	{
		std::cout << "Type command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		for (int i = 0; command[i]; i++)
			command[i] = (char)std::toupper(command[i]);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		if (command == "EXIT" || std::cin.eof())
			break;
	}
	return (0);
}
