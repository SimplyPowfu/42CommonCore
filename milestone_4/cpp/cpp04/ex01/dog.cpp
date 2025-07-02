/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:20:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 19:51:36 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
}

Dog::Dog(Dog const& copy)
{
	std::cout << "Copy of Dog" << std::endl;
	brain = new Brain(*copy.brain);
}

Dog&	Dog::operator=(Dog const& copy) 
{
	std::cout << "Copy operator of Dog" << std::endl;
	if (&copy != this)
	{
		Animal::operator=(copy);
		if (brain)
			delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Distructor a " << _type << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bau Bau!" << std::endl;
}

void Dog::addIdea(std::string idea)
{
	brain->addIdea(idea);
}

void Dog::showIdea(int i)
{
	brain->showIdea(i);
}

Brain*	Dog::getBrain() const { return(brain); }