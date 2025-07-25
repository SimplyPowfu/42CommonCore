/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:07:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/25 13:44:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include <cctype>

# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _sign;
	const int _signGrade;
	const int _executeGrade;
public:
	Form();
	Form(const std::string _name, const int _signGrade, const int _executeGrade);
	Form(const Form &copy);
	~Form();
	
	Form &operator=(const Form &copy);
	
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	std::string const	getName() const;
	bool				getSign() const;
	void				beSigned(Bureaucrat const &b);
	
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
};

std::ostream& operator<<(std::ostream& out, const Form &form);

#endif