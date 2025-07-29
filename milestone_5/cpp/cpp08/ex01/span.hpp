/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 12:33:20 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

class Span
{
private:
	unsigned int	N;
	std::vector<int> v;
public:
	Span(unsigned int n);
	Span(Span const& copy);
	Span& operator=(Span const& copy);
	~Span();
	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			addRange(int first, int last);

	class FullStore : public std::exception
	{
		virtual const char* what() const throw();
	};
	class NotEnoughNumbers : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif