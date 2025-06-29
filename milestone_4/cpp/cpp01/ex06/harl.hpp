/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:38:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/28 19:43:16 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <iomanip>
# include <cctype>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void (Harl::*Complains[4])(void);
public:
	Harl();
	void complain(std::string level);
};

#endif