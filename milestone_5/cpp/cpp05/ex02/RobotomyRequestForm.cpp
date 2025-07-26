/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:14:53 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 12:04:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default target")
{
	std::cout <<"Default RobotomyRequestForm Costructor created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("default", 72, 45), _target(t)
{
	std::cout << "RobotomyRequestForm Costructor created" << std::endl;
	if (getSignGrade() < 1 || getExecuteGrade() < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy) : AForm(copy)
{
	std::cout << "RobotomyRequestForm Copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Distructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const& robot)
{
	out << robot.getName() << ", Form execute grade " << robot.getExecuteGrade() << ", Form sign grade " << robot.getSignGrade();
	if (robot.getSign())
		out << ", the form is signed";
	else
		out << ", the form isn't signed";
	return (out);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw AForm::NotSigned();
	srandom(time(NULL));
	long ran = random() % 2;
	std::cout << ran << std::endl;
	if (ran == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}