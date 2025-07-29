/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

template <typename T>
int	easyfind(T &container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw std::exception();
	return *std::find(container.begin(), container.end(), n);
}

#endif