/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 13:49:29 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main() {
	Data original;
	original.str = "ciao";
	original.n = 42;

	unsigned long raw = Serialization::serialize(&original);
	Data* copy = Serialization::deserialize(raw);

	std::cout << "Original: " << original.str << ", " << original.n << std::endl;
	std::cout << "address in long: " << raw << std::endl;
	std::cout << "Copy: " << copy->str << ", " << copy->n << std::endl;

	return (0);
}