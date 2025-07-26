/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:30:36 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/25 19:57:09 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(1), _executeGrade(1), _sign(false) 
{
	std::cout << _name << " Costructor created" << std::endl;
}

AForm::AForm(const std::string _name, const int _signGrade, const int _executeGrade) : _name(_name), _signGrade(_signGrade), _executeGrade(_executeGrade), _sign(false) 
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << _name << " Costructor created" << std::endl;
}

AForm::AForm(const AForm& copy) : _signGrade(_signGrade), _executeGrade(_executeGrade)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

AForm::~AForm() 
{
	std::cout << _name << " Distructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const AForm &Aform)
{
	out << Aform.getName() << " Aform execute grade: " << Aform.getExecuteGrade() << ", AForm sign grade: " << Aform.getSignGrade();
	if (Aform.getSign())
		out << ", the Aform is signed";
	else
		out << ", the Aform isn't signed";
	return (out);
}

std::string const	AForm::getName() const { return(_name); }
int					AForm::getSignGrade() const { return(_signGrade); }
int					AForm::getExecuteGrade() const { return(_executeGrade); }
bool				AForm::getSign() const { return(_sign); }

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() >= this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::NotSigned::what() const throw()
{
	return ("Form is not signed");
}