/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:23:43 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 17:29:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <cctype>
# include <string>

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(AMateria const& copy);
	AMateria& operator=(AMateria const& copy);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* Add() const = 0;
	virtual void use(ICharacter& target);
};

#endif