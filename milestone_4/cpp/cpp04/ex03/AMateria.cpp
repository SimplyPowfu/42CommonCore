/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:58 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 19:01:23 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria() : type("AMateria") 
{
	// std::cout << "Costruction AMateria" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	// std::cout << "Copy AMateria" << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const& copy) : type(copy.type) 
{
	// std::cout << "Copy AMateria" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const& copy) 
{
	// std::cout << "Copy operator AMateria" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "distruction AMateria" << std::endl;
}

std::string const& AMateria::getType() const {return (this->type);}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << std::endl;
}