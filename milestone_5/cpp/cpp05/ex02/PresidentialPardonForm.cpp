/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:14:53 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 12:14:50 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default target")
{
	std::cout <<"Default PresidentialPardonForm Costructor created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("default", 25, 5), _target(t)
{
	std::cout << "PresidentialPardonForm Costructor created" << std::endl;
	if (getSignGrade() < 1 || getExecuteGrade() < 1)
		throw PresidentialPardonForm::GradeTooHighException();
	else if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy) : AForm(copy)
{
	std::cout << "PresidentialPardonForm Copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Distructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm const& shru)
{
	out << shru.getName() << ", Form execute grade " << shru.getExecuteGrade() << ", Form sign grade " << shru.getSignGrade();
	if (shru.getSign())
		out << ", the form is signed";
	else
		out << ", the form isn't signed";
	return (out);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw AForm::NotSigned();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}