/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:09:45 by francesco         #+#    #+#             */
/*   Updated: 2025/07/26 12:31:34 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();

		Intern &operator=(Intern const &copy);

		AForm	*makeForm(std::string const &name, std::string const &target);
		AForm	*createShrubberyCreationForm(std::string const &target);
		AForm	*createRobotomyRequestForm(std::string const &target);
		AForm	*createPresidentialPardonForm(std::string const &target);

	public:
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif