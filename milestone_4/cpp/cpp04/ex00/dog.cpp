/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:20:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 15:46:04 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::~Dog() {std::cout << "Distructor a " << _type << std::endl;}

void Dog::makeSound() const
{
	std::cout << "Bau Bau!" << std::endl;
}