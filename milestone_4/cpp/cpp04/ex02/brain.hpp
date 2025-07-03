/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:47:20 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/02 19:51:26 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "animal.hpp"

class Brain
{
protected:
	int			index;
	std::string ideas[100];
public:
	Brain();
	Brain(Brain const& copy);
	Brain& operator=(Brain const& copy);
	virtual ~Brain();

	void	addIdea(std::string idea);
	void	showIdea(int i);
};


#endif