/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:14:53 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 12:23:20 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default target")
{
	std::cout <<"Default ShrubberyCreationForm Costructor created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("default", 145, 137), _target(t)
{
	std::cout << "ShrubberyCreationForm Costructor created" << std::endl;
	if (getSignGrade() < 1 || getExecuteGrade() < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy) : AForm(copy)
{
	std::cout << "ShrubberyCreationForm Copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Distructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const& shru)
{
	out << shru.getName() << ", Form execute grade " << shru.getExecuteGrade() << ", Form sign grade " << shru.getSignGrade();
	if (shru.getSign())
		out << ", the form is signed";
	else
		out << ", the form isn't signed";
	return (out);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!getSign())
		throw AForm::NotSigned();
	std::fstream file;
	std::string filename = _target + "_shrubbery";
	file.open(filename.c_str(), std::ios::out);
	std::string tree =
	"                                  # #### ####\n"
	"                                ### \\/#|### |/####\n"
	"                               ##\\/## \\||/##/_/##/_#\n"
	"                             ###  \\/###|/ \\/ # ###\n"
	"                           ##_\\_#\\_\\## | #/###_/_####\n"
	"                          ## #### # \\ #| /  #### ##/##\n"
	"                           __#_--###`  |{,###---###-~\n"
	"                                     \\ }{\n"
	"                                      }}{\n"
	"                                      }}{\n"
	"                                      {{}}\n"
	"                                , -=-~{ .-^- _\n"
	"                                      `}\n"
	"                                       {\n";
	file << tree;
	file.close();
	std::cout << "Shrubbery tree has been created in " << filename << std::endl;
}