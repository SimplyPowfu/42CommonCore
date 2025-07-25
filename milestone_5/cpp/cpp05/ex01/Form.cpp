/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:30:36 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/25 17:57:14 by ecarbona         ###   ########.fr       */
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

Form::Form(const Form& copy) : _signGrade(_signGrade), _executeGrade(_executeGrade)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

Form::~Form() 
{
	std::cout << _name << " Distructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
	out << form.getName() << " form execute grade: " << form.getExecuteGrade() << ", Form sign grade: " << form.getSignGrade();
	if (form.getSign())
		out << ", the form is signed";
	else
		out << ", the form isn't signed";
	return (out);
}

std::string const	Form::getName() const { return(_name); }
int					Form::getSignGrade() const { return(_signGrade); }
int					Form::getExecuteGrade() const { return(_executeGrade); }
bool				Form::getSign() const { return(_sign); }

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() >= this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}