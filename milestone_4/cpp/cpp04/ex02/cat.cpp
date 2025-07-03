/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:20:37 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 19:51:33 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
}

Cat::Cat(Cat const& copy)
{
	std::cout << "Copy of Cat" << std::endl;
	brain = new Brain(*copy.brain);
}

Cat&	Cat::operator=(Cat const& copy) 
{
	std::cout << "Copy operator of Cat" << std::endl;
	if (&copy != this)
	{
		Animal::operator=(copy);
		if (brain)
			delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Distructor a " << _type << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow meow ᓚᘏᗢ !" << std::endl;
}

void Cat::addIdea(std::string idea)
{
	brain->addIdea(idea);
}

void Cat::showIdea(int i)
{
	brain->showIdea(i);
}

Brain*	Cat::getBrain() const { return(brain); }