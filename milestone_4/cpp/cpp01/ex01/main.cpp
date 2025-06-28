/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:55:40 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/28 17:53:18 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main()
{
	Zombie* horde;
	int		num = 0;
	std::string	name;

	std::cout << "zombie name: ";
	getline(std::cin, name);
	if (std::cin.eof())
		return (0);
	std::cout << "zombie num: ";
	if (std::cin.eof())
		return (0);
	std::cin >> num;
	horde = zombieHorde(num, name);
	for (int i = 0; i < num; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}