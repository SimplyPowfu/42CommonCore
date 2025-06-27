/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:55:40 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/27 19:05:27 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string stringREF = string;

	std::cout	<< "address of the string variable: " << &string 
				<< "\naddress stringPTR: " << stringPTR
				<< "\naddress stringREF: " << &stringREF
				<< "\nvalue of the string variable: " << string 
				<< "\nvalue stringPTR: " << *stringPTR
				<< "\nvalue stringREF: " << stringREF
				<< std::endl;
	return (0);
}