/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:07:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 11:07:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _sign;
	const int _signGrade;
	const int _executeGrade;
public:
	AForm();
	AForm(const std::string _name, const int _signGrade, const int _executeGrade);
	AForm(const AForm &copy);
	~AForm();
	
	AForm &operator=(const AForm &copy);
	
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	std::string const	getName() const;
	bool				getSign() const;
	void				beSigned(Bureaucrat const &b);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	
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
	class NotSigned : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm &Aform);

#endif