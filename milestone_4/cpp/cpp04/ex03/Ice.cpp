/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:22:45 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 17:29:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp" 


Ice::Ice() : AMateria("ice") 
{
	std::cout << "Costruction Ice" << std::endl;
}

Ice::Ice(Ice const& copy) : AMateria(copy.type) 
{
	std::cout << "Copy Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "distruction Ice" << std::endl;
}

Ice&	Ice::operator=(Ice const& copy) 
{
	std::cout << "Copy operator Ice" << std::endl;
	if (&copy != this)
		this->type = copy.type;
	return (*this);
}

std::string	const& Ice::getType() const {return (this->type);}

Ice*	Ice::Add() const{return (new Ice());}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}