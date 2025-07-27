/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 20:58:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Func.hpp"

int main()
{
	std::cout << "base ";
	Base *base = generate();
	std::cout << "base2 ";
	Base *base2 = generate();
	std::cout << "*base3 ";
	Base *base3 = generate();
	std::cout << "base4 is NULL" <<  std::endl; 
	Base *base4 = NULL;
	Base &ref = *base;
	std::cout << "ref "; 
	identify(ref);
	std::cout << "base "; 
	identify(base);
	std::cout << "*base "; 
	identify(*base);
	std::cout << "base2 "; 
	identify(base2);
	std::cout << "*base2 "; 
	identify(*base2);
	std::cout << "base3 "; 
	identify(base3);
	std::cout << "*base3 ";
	identify(*base3);
	std::cout << "base4 "; 
	identify(base4);
	delete base;
	delete base2;
	delete base3;
	return 0;
}