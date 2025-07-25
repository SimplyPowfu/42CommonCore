/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:21:18 by francesco         #+#    #+#             */
/*   Updated: 2025/07/25 19:55:34 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat jack("Jack", 75);
    Form form1("Form_1", 80, 80);
	std::cout << std::endl;
    
    std::cout << form1 << std::endl << std::endl;
    try {
        jack.signForm(form1);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl << form1 << std::endl << std::endl;

    Bureaucrat bob("Bob", 120);
	std::cout << std::endl;
    try {
        bob.signForm(form1);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
