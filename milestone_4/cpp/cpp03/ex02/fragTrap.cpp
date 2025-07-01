/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:02:43 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/01 17:09:34 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "created default FragTrap" << std::endl;
	this->name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	std::cout << "FragTrap " << name << " costructed" << std::endl;
	this->name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy) 
    {
		name = copy.name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
    return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " decostructed" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << ": You want a high five?" << std::endl;
}