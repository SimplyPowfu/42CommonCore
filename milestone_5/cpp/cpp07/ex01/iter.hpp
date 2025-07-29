/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:03:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/28 15:54:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <climits>

template <typename T, typename F>
void iter(T *array, size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif