/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:30:36 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/25 13:45:45 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(1), _executeGrade(1), _sign(false) 
{
	std::cout << _name << " Costructor created" << std::endl;
}

Form::Form(const std::string _name, const int _signGrade, const int _executeGrade) : _name("default"), _signGrade(_signGrade), _executeGrade(_executeGrade), _sign(false) 
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << _name << " Costructor created" << std::endl;
}