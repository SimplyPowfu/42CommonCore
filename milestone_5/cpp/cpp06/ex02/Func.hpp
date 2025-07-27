/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:20:33 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/27 20:45:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HPP
# define FUNC_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate( void );
void identify( Base *p );
void identify( Base &p );

#endif