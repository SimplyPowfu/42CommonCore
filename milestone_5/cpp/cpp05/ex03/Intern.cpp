/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:30:26 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 13:02:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout <<"Default Intern Costructor created" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern Copy constructor" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern Distructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

AForm* Intern::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Not find a AForm";
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
	struct forms {
		const char* formName;
		AForm* (Intern::*createForm)(std::string const &target);
	};
	forms forms[] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };			
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i].formName)
			return (this->*forms[i].createForm)(target);
	}
	throw Intern::FormNotFoundException();
	return (NULL);
}