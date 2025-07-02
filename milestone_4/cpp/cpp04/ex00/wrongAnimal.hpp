/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:55 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 15:57:45 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	~WrongAnimal();

	void makeSound(void) const;
	std::string getType(void) const;
};


#endif