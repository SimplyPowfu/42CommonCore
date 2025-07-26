/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:00:07 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 17:25:11 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int		get_type(std::string const &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "nan")
		return (-1);
	if (str == "")
		return (0);
	if (str.find_first_not_of("0123456789.-+f") || str.size() == 1)
		return (1);
	return (5);
}

void	charLiteral(std::string const &str)
{
	char c;
	if (str.find_first_not_of("0123456789.-+f"))
		c = static_cast<char>(std::stoi(str));
	else
		c = str[0];
	if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
	else
        std::cout << "char: Non displayable" << std::endl;
}

void	intLiteral(std::string const &str)
{
	int i;
	if (str.find_first_not_of("0123456789.-+f"))
		i = std::stoi(str);
	else
		i = static_cast<int>(str[0]);
	std::cout << "int: "<< i << std::endl;
}

void	floatLiteral(std::string const &str)
{
	float f;
	if (str.find_first_not_of("0123456789.-+f"))
		f = std::stof(str);
	else
		f = static_cast<float>(str[0]);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	doubleLiteral(std::string const &str)
{
	double d;
	if (str.find_first_not_of("0123456789.-+f"))
		d = std::stof(str);
	else
		d = static_cast<double>(str[0]);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	PseudoLiteral(std::string const &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl; 
    }
    else if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}