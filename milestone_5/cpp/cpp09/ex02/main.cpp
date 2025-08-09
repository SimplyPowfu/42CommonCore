/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/09 15:20:07 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "Error: wrong number of arguments" << std::endl, 1);
	try{
		PmergeMe list;
		list.store_numbers(argc, argv);
	} catch (const std::exception& e) {
		return (std::cerr << e.what() << std::endl, 1);
	}
	return (0);
}
