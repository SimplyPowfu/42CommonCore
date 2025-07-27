/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 11:31:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <climits>

struct Data {
	std::string str;
	int         n;
};

class Serialization
{
public:
	Serialization();
	Serialization(Serialization const &copy);
	Serialization &operator=(Serialization const &copy);
	~Serialization();
	static unsigned long serialize(Data* ptr);
	static Data* deserialize(unsigned long raw);
};

#endif