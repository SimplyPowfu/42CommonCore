/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:05:48 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 19:01:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index(0)
{
	// std::cout << "Costruction MateriaSource" << std::endl;
	for (int i = 0; i < 10; i++)
		Learned[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& copy) 
{
	// std::cout << "Copy MateriaSource" << std::endl;
	if (&copy != this)
		*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 10; i++)
		delete Learned[i];
	// std::cout << "distruction MateriaSource" << std::endl;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& copy) 
{
	// std::cout << "Copy operator MateriaSource" << std::endl;
	if (&copy != this)
		*this = copy;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* mat)
{
	if (!mat)
		return ;
	for (int i = 0; i < 10; i++)
		if (Learned[i] && mat->getType() == Learned[i]->getType())
			return ;
	if (index < 10)
	{
		Learned[index] = mat;
		index++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i) 
    {
        if (Learned[i] && Learned[i]->getType() == type) 
            return Learned[i]->Add();
    }
    return NULL;
}