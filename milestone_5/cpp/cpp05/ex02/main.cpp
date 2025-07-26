/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/07/26 12:27:29 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
	Bureaucrat bob("Bob", 1);
	Bureaucrat jack("Jack", 75);
	std::cout << std::endl;

//SHRUBERRY TEST
	try {
		std::cout << "SHRUBBERYCREATIONFORM TEST" << std::endl;
		ShrubberyCreationForm AForm("tree");
		jack.executeForm(AForm);
		std::cout << std::endl;
		jack.signForm(AForm);
		std::cout << std::endl;
		jack.executeForm(AForm);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
//ROBOT TEST
	try {
		std::cout << "ROBOTOMYREQUESTFORM TEST" << std::endl;
		RobotomyRequestForm AForm("robot");
		bob.signForm(AForm);
		AForm.execute(bob);
		std::cout << std::endl;
		AForm.execute(jack);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
//PRESIDENTIAL TEST
	try {
		std::cout << "PRESIDENTIALPARDONFORM TEST" << std::endl;
		PresidentialPardonForm AForm("president");
		bob.signForm(AForm);
		AForm.execute(bob);
		std::cout << std::endl;
		AForm.execute(jack);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
