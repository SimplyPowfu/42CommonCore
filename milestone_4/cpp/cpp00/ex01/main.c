/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:19:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/18 20:10:50 by ecarbona         ###   ########.fr       */
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
			command[i] = std::toupper(command[i]);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT" || std::cin.eof())
			break;
	}
	if (std::cin.eof())
		std::cout << std::endl;
	return (0);
}
