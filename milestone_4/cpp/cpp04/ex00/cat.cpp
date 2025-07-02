/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:20:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 15:54:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::~Cat() {std::cout << "Distructor a " << _type << std::endl;}

void Cat::makeSound() const
{
	std::cout << "meow meow ᓚᘏᗢ !" << std::endl;
}