/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/09 11:36:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <vector>
# include <climits>
# include <iomanip>
# include <set>
# include <stack>
# include <iostream>
# include <fstream>
# include <map>

class PmergeMe
{
private:
public:
	PmergeMe();
	PmergeMe(PmergeMe const& copy);
	PmergeMe& operator=(PmergeMe const& copy);
	~PmergeMe();
};

#endif