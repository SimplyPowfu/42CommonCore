/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:55:40 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/29 21:58:07 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

int main()
{
	std::string string;
	std::cout << std::boolalpha;

    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);

	std::cout << "chose one case [inside, edge, vertice, ouside]: ";
	std::getline(std::cin, string);
	if (std::cin.eof())
		return (std::cout << std::endl, 0);
	if (string == "inside")
	{
		std::cout << "Testing with points inside the triangle:" << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(1, 1): " << bsp(a, b, c, Point(1, 1)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(1, 2): " << bsp(a, b, c, Point(1, 2)) << std::endl;
	}
	else if (string == "edge")
    {
		std::cout << "Testing with points on the edges of the triangle:" << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(0, 3): " << bsp(a, b, c, Point(0, 3)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(2.5, 0): " << bsp(a, b, c, Point(2.5, 0)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(2.5, 2.5): " << bsp(a, b, c, Point(2.5, 2.5)) << std::endl;
	}
	else if (string == "vertice")
    {
		std::cout << "Testing with points at the vertices of the triangle:" << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(0, 0): " << bsp(a, b, c, Point(0, 0)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(0, 5): " << bsp(a, b, c, Point(0, 5)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(5, 0): " << bsp(a, b, c, Point(5, 0)) << std::endl;
	}
	else if (string == "outside")
    {
		std::cout << "Testing with points outside the triangle:" << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(10, 10): " << bsp(a, b, c, Point(10, 10)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(-1, -1): " << bsp(a, b, c, Point(-1, -1)) << std::endl;
		std::cout << "a(0, 0), b(0, 5), c(5, 0), point(6, 6): " << bsp(a, b, c, Point(6, 6)) << std::endl;
	}
	else
		std::cout << "try another case bro..." << std::endl;
	return (0);
}
