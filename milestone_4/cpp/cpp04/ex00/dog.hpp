/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:55 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 15:47:03 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();

	void makeSound(void) const;
};


#endif