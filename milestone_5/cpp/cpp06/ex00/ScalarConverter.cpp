/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:08:16 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 17:18:03 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Costructor created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter() 
{
	std::cout << "Distructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

void ScalarConverter::convert(std::string const &str)
{
	int type = get_type(str);
	switch (type)
	{
		case -1:
			PseudoLiteral(str);
			break;
		case 0:
			std::cerr << "Error: empty string" << std::endl;
			break;
		case 1:
			charLiteral(str);
		case 2:
			intLiteral(str);
		case 3:
			floatLiteral(str);
		case 4:
			doubleLiteral(str);
			break;
		default:
			std::cerr << "Error: invalid string" << std::endl;
	}
}