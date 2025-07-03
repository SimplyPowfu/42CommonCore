/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:22:45 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 18:03:15 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Character.hpp" 


Cure::Cure() : AMateria("cure") 
{
	std::cout << "Costruction Cure" << std::endl;
}

Cure::Cure(Cure const& copy) : AMateria(copy.type) 
{
	std::cout << "Copy Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "distruction Cure" << std::endl;
}

Cure&	Cure::operator=(Cure const& copy) 
{
	std::cout << "Copy operator Cure" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);
}

std::string	const& Cure::getType() const {return (this->type);}

Cure*	Cure::Add() const{return (new Cure());}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}