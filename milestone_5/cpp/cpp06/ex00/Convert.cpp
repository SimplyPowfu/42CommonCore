/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:00:07 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 11:22:11 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

#include <string>
#include <stdexcept>
#include <cctype>

double ft_stod(const std::string &str)
{
	size_t i = 0;
	double result = 0.0;
	int sign = 1;
	bool has_digits = false;

	while (i < str.size() && std::isspace(str[i]))
		i++;
	if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < str.size() && std::isdigit(str[i])) {
		has_digits = true;
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i < str.size() && str[i] == '.') {
		i++;
		double fraction = 0.0;
		double divisor = 10.0;
		while (i < str.size() && std::isdigit(str[i])) {
			has_digits = true;
			fraction += (str[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
		result += fraction;
	}
	if (i < str.size() && str[i] == 'f')
		i++;
	return result * sign;
}

int		get_type(std::string const &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "nan")
		return (-1);
	if (str.empty())
		return (0);
	if (str.find_first_not_of("0123456789.-+f") || str.size() == 1)
		return (1);
	return (5);
}

void	charLiteral(std::string const &str)
{
	double d;
	if (str.find_first_not_of("0123456789.-+f"))
		d = ft_stod(str);
	else
		d = static_cast<char>(str[0]);
	if (d < 0 || d > 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (std::isprint(static_cast<char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	intLiteral(std::string const &str)
{
	double i;
	if (str.find_first_not_of("0123456789.-+f"))
		i = (ft_stod(str));
	else
		i = static_cast<int>(str[0]);
	if (i < INT_MIN || i > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
}

void	floatLiteral(std::string const &str)
{
	float f;
	if (str.find_first_not_of("0123456789.-+f"))
		f = static_cast<float>(ft_stod(str));
	else
		f = static_cast<float>(str[0]);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	doubleLiteral(std::string const &str)
{
	double d;
	if (str.find_first_not_of("0123456789.-+f"))
		d = ft_stod(str);
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
