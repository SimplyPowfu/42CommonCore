/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:54 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/30 19:57:30 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

int	main()
{
	ClapTrap clap("Mario");
	clap.attack("Luigi");
	clap.takeDamage(4);
	clap.beRepaired(5);
}