/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/08 18:07:21 by ecarbona         ###   ########.fr       */
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
	std::stack<int>	_number;
	std::string		_string;
	int				_result;
public:
	RPN();
	RPN(RPN const& copy);
	RPN& operator=(RPN const& copy);
	~RPN();

	void	calculate();
	int 	getResult();
};

#endif