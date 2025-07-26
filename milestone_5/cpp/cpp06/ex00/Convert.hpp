/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:07:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/26 16:54:28 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <cctype>

int		 	get_type(std::string const &str);
void		charLiteral(std::string const &str);
void		intLiteral(std::string const &str);
void		floatLiteral(std::string const &str);
void		doubleLiteral(std::string const &str);
void		PseudoLiteral(std::string const &str);

#endif