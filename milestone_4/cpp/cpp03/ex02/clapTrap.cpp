/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:20:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/01 17:02:41 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "created default ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " costructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " decostructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "Invalid attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Invalid attack" << std::endl;
		return ;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << name << " lost " << amount << " points of Hit!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "Invalid heal" << std::endl;
		return ;
	}
	_energyPoints--;
	if (amount + _hitPoints >= _hitPoints)
		_hitPoints = 10;
	else
		_hitPoints += amount;
	std::cout << "ClapTrap " << name << " heal " << amount <<  " points of Hit!" << std::endl;
}