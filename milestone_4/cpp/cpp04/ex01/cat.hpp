/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:55 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 19:51:18 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "animal.hpp"
# include "brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(Cat const& copy);
	Cat&	operator=(Cat const& copy);
	~Cat();

	void	makeSound(void) const;
	void	addIdea(std::string idea);
	void	showIdea(int i);
	Brain*	getBrain() const;
};


#endif