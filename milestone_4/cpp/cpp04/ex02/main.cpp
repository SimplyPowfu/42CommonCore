/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:54 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 15:45:03 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Dog dog;
	dog.getBrain()->addIdea("buoni i croccantini");
	dog.showIdea(0);
	dog.makeSound();

	Cat cat;
	cat.getBrain()->addIdea("meglio l'umido");
	cat.showIdea(0);
	cat.makeSound();

	delete j;
	delete i;
	return 0;
}