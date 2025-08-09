/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/09 11:36:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <vector>
# include <climits>
# include <iomanip>
# include <set>
# include <stack>
# include <iostream>
# include <fstream>
# include <map>

class RPN
{
private:
	static std::stack<int>	_stack;
public:
	RPN();
	RPN(RPN const& copy);
	RPN& operator=(RPN const& copy);
	~RPN();

	static void	calculate(char *input);
};

#endif