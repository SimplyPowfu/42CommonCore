/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:39:32 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 13:41:58 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
	std::cout << "Costructor created" << std::endl;
}

Serialization::Serialization(const Serialization& copy)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

Serialization::~Serialization() 
{
	std::cout << "Distructor called" << std::endl;
}

Serialization &Serialization::operator=(const Serialization &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

unsigned long Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

Data* Serialization::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data*>(raw);
}