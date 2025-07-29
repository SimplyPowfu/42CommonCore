/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 11:33:48 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(66);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	try
	{
		std::cout << easyfind(v, 66) << std::endl;
		std::cout << easyfind(v, 5) << std::endl;
		std::cout << easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Element not found" << std::endl;
	}
	return (0);
}