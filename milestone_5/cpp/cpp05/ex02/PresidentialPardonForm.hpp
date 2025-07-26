/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:13:52 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 12:12:37 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm : public AForm
{
private:
	std::string const _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string t);
	PresidentialPardonForm(PresidentialPardonForm const& copy);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& copy);
	~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm const& rhs);

#endif