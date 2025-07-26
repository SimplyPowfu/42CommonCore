/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:07:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 16:08:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include "Convert.hpp"

class ScalarConverter
{
private:

public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(ScalarConverter const &copy);
	~ScalarConverter();
	static void convert(std::string const &str);
};

#endif