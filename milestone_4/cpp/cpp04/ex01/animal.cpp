/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:20:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 15:34:52 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal() : _type("Animal") 
{
	std::cout << "Costructor a " << _type << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
	std::cout << "Costructor a " << type << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

Animal::~Animal() 
{
	std::cout << "Distructor a " << _type << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) const { return(_type); }