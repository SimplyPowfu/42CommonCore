/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:00:07 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 19:09:15 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"


Character::Character() : index(0), name("default")
{
	// std::cout << "Costruction Character" << std::endl;
	for (int i = 0; i < 4; i++)
		invetory[i] = NULL;
}

Character::Character(std::string const& name) : index(0)
{
	// std::cout << "Costruction "<< name <<" Character" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		invetory[i] = NULL;
}

Character::Character(Character const& copy): name(copy.name) 
{
    for (int i = 0; i < 4; ++i) 
    {
        if (copy.invetory[i]) 
            invetory[i] = copy.invetory[i]->Add();
        else 
            invetory[i] = NULL;
    }
}

Character&	Character::operator=(Character const& copy)
{
    if (this != &copy) 
    {
        name = copy.name;
        for (int i = 0; i < 4; ++i) 
        {
            if (invetory[i]) 
                delete invetory[i];
            if (copy.invetory[i]) 
                invetory[i] = copy.invetory[i]->Add();
            else
                invetory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (invetory[i]) 
            delete invetory[i];
	// std::cout << "distruction Character" << std::endl;
}

std::string const & Character::getName() const {return (this->name);}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i) 
    {
        if (!invetory[i]) 
        {
            invetory[i] = m;
            break;
        }
    }
}

void	Character::unequip(int index)
{
	if (index >= 0 && index < 4)
		this->invetory[index] = NULL;
}

void	Character::use(int index, ICharacter& target)
{
	
	if (index >= 0 && index < 4 && this->invetory[index])
		this->invetory[index]->use(target);
}