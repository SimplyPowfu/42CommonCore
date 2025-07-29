/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:03:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/28 15:11:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <climits>

template <typename T>
void	swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T &a, const T &b)
{
	if (b <= a)
		return (b);
	else
		return (a);
}

template <typename T>
T	max(const T &a, const T &b)
{
	if (b >= a)
		return (b);
	else
		return (a);
}

#endif