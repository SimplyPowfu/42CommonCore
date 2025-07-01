/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:02:43 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/01 17:36:30 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "created default FragTrap" << std::endl;
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	std::cout << "FragTrap " << name << " costructed" << std::endl;
	this->_name = name;
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
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
    return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " decostructed" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << ": You want a high five?" << std::endl;
}