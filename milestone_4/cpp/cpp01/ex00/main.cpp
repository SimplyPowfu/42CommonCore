/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:55:40 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/27 18:51:26 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main()
{
	std::string	name;

	std::cout << "zombie name: ";
	getline(std::cin, name);
	if (std::cin.eof())
		return (0);	
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;
	randomChump(name);
	return (0);
}