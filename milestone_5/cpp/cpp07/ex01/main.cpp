/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:43:45 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/28 15:53:35 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printTemplate(const T& element)
{
	std::cout << element << " ";
}

int main( void ) {
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printTemplate<int>);
    std::cout << std::endl;
    char charArray[] = {'c','i','a','o'};
    iter(charArray, 4, printTemplate<char>);
    std::cout << std::endl;
	return 0;
}