/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 12:43:44 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return (0);
// }

int main()
{
	// Caso base
	std::cout << "=== Caso base ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	// Caso di overflow (FullStore)
	std::cout << "\n=== Caso: FullStore ===" << std::endl;
	try {
		sp.addNumber(42); // oltre la capacità
	} catch (const std::exception &e) {
		std::cout << "Eccezione catturata: " << e.what() << std::endl;
	}

	// Caso con un solo numero
	std::cout << "\n=== Caso: solo un numero ===" << std::endl;
	try {
		Span one(1);
		one.addNumber(5);
		std::cout << one.shortestSpan() << std::endl; // dovrebbe lanciare
	} catch (const std::exception &e) {
		std::cout << "Eccezione catturata: " << e.what() << std::endl;
	}

	// Caso con addRange valido
	std::cout << "\n=== Caso: addRange valido ===" << std::endl;
	try {
		Span rangeSpan(10);
		rangeSpan.addRange(10, 15); // aggiunge 10,11,12,13,14,15
		std::cout << "Shortest Span: " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << rangeSpan.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Eccezione: " << e.what() << std::endl;
	}

	// Caso addRange che supera la capacità
	std::cout << "\n=== Caso: addRange overflow ===" << std::endl;
	try {
		Span overflowSpan(3);
		overflowSpan.addRange(1, 5); // 1,2,3,4,5 (5 numeri > 3)
	} catch (const std::exception &e) {
		std::cout << "Eccezione catturata: " << e.what() << std::endl;
	}

	return 0;
}
