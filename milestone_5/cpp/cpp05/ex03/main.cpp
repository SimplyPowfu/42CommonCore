/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/07/26 13:05:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
//INTERN TEST
	try {
		std::cout << "INTERN TEST" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << rrf->getName();
		if (rrf->getSign() == 0)
			std::cout << " not signed" << std::endl;
		else
			std::cout << " signed" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
