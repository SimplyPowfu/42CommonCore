/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:07:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 11:34:28 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();
	
	Bureaucrat &operator=(const Bureaucrat &copy);

//eccezioni
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	
	std::string const	getName() const;
	int		getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm &Aform);
	void	executeForm(const AForm& form);

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat);

#endif