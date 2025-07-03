/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:25:46 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/03 18:19:37 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria	*invetory[4];
	int			index;
	std::string	name;

public:
	Character();
	Character(std::string const& name);
	Character(Character const& copy);
	Character& operator=(Character const& copy);
	~Character();
	std::string const & getName() const;
	void	equip(AMateria* m);
	void	unequip(int index);
	void	use(int index, ICharacter& target);
};

#endif