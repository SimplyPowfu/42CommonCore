/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/07/25 19:33:04 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "||||||BUREAUCRAT INSTATIATE TESTS||||||\n" << std::endl;

	try {
		std::cout << "Trying to create a bureaucrat with a grade of 0:" << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to create a bureaucrat with a grade of 151:" << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Bureaucrat bureaucrat_0;
	Bureaucrat bureaucrat_1("Jack", 75);

	std::cout << "\n||||||BUREAUCRAT TESTS||||||\n" << std::endl;

	try {
		std::cout << "-----Before Decrement-----" << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" << bureaucrat_0.getGrade() << std::endl;

		std::cout << "-----After Decrement-----" << std::endl;
		bureaucrat_0.decrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" << bureaucrat_0.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "-----Before Increment-----" << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:" << bureaucrat_1.getGrade() << std::endl;

		std::cout << "-----After Increment-----" << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:" << bureaucrat_1.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n||||||FORM TESTS||||||\n" << std::endl;

	Form form_0;
	Form form_1("Form_1", 80, 80);

	try {
		std::cout << "-----Trying to sign-----" << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:" << bureaucrat_0.getGrade() << std::endl;
		bureaucrat_1.signForm(form_1);//fail form 0, succes form 1
		form_1.beSigned(bureaucrat_1);//fail form 0, succes form 1
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}