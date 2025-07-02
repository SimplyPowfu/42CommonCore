/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:55 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 15:51:52 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();

	void makeSound(void) const;
};


#endif