/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:13:52 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 11:28:43 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string const _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string t);
	ShrubberyCreationForm(ShrubberyCreationForm const& copy);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& copy);
	~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif