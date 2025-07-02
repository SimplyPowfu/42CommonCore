/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:14:54 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 16:46:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete meta;
	delete j;
	std::cout << std::endl;
	const WrongAnimal* z = new WrongAnimal();
	const WrongAnimal* x = new WrongCat();
	std::cout << z->getType() << " " << std::endl;
	std::cout << x->getType() << " " << std::endl;
	z->makeSound();
	x->makeSound();
	delete z;
	delete x;

	return (0);
}