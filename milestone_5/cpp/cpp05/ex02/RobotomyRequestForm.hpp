/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:13:52 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 11:47:06 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>

class RobotomyRequestForm : public AForm
{
private:
	std::string const _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string t);
	RobotomyRequestForm(RobotomyRequestForm const& copy);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& copy);
	~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif