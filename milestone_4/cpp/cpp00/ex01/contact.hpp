/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:06:25 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/18 20:07:40 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cctype>

class	Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string phoneNumber;
	std::string address;
public:
	void	setContact();
};

#endif