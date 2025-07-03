/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:00:07 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 18:18:51 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"


Character::Character() : index(0), name("default")
{
	std::cout << "Costruction Character" << std::endl;
	for (int i = 0; i < 4; i++)
		invetory[i] = NULL;
}

Character::Character(std::string const& name) : index(0)
{
	std::cout << "Costruction "<< name <<" Character" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		invetory[i] = NULL;
}

Character::Character(Character const& copy)
{
	std::cout << "Copy Character" << std::endl;
	*this = copy;
}

Character&	Character::operator=(Character const& copy) 
{
	std::cout << "Copy operator Character" << std::endl;
	if (&copy != this)
		*this = copy;
	return (*this);
}

Character::~Character()
{
	std::cout << "distruction Character" << std::endl;
}

std::string const & Character::getName() const {return (this->name);}

void	Character::equip(AMateria* m)
{
	if (m != NULL && this->index < 4)
	{
		this->invetory[this->index] = m;
		this->index++;
	}
}

void	Character::unequip(int index)
{
	if (index >= 0 && index < 4 && this->invetory[index] != NULL)
	{
		this->invetory[index] = NULL;
		this->index--;
	}
}

void	Character::use(int index, ICharacter& target)
{
	
	if (index >= 0 && index < 4 && this->invetory[index] != NULL)
	{
		this->invetory[index]->use(target);
		this->invetory[index] = NULL;
		this->index--;
	}
}