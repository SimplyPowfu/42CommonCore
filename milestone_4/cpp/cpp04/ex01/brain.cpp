/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:50:43 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 19:51:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain() : index(0) 
{
	std::cout << "Costructor a Brain" << std::endl;
}

Brain::Brain(Brain const& copy)
{
	std::cout << "Copy of Brain" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Distructor a Brain" << std::endl;
}

Brain&	Brain::operator=(Brain const& copy) 
{
	std::cout << "Copy operator of Brain" << std::endl;
	if (&copy != this)
	{
		index = copy.index;
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
	}
	return (*this);
}

void	Brain::addIdea(std::string idea)
{
	if (index < 100)
	{
		ideas[index] = idea;
		index++;
	}
	else
		std::cout << "No more space for ideas..." << std::endl;
}

void	Brain::showIdea(int i)
{
	if (i >= 0 && i < 100)
		std::cout << ideas[i] << std::endl;
	else
		std::cout << "Wrong Index" << std::endl;
}