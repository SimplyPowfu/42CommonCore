/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:55:40 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 17:26:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return ( std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; argv[1][i]; i++)
		argv[1][i] = (char)std::toupper(argv[1][i]);
	int i = 0;
	while (i < 4 && argv[1] != levels[i])
		i++;
	switch (i)//switch the most useless thing in dev. if else is better
	{
		case 0: harl.complain(argv[1]);
		case 1: harl.complain(argv[1]);
		case 2: harl.complain(argv[1]);
		case 3: harl.complain(argv[1]);break;
		default: std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;return (1);
	}
	return (0);
}
