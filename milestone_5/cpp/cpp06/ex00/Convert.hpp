/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:07:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 11:02:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <climits>

int		 	get_type(std::string const &str);
void		charLiteral(std::string const &str);
void		intLiteral(std::string const &str);
void		floatLiteral(std::string const &str);
void		doubleLiteral(std::string const &str);
void		PseudoLiteral(std::string const &str);

#endif