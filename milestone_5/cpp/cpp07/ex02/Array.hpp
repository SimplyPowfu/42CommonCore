/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:03:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/28 16:50:34 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <climits>

template <typename T>
class Array
{
private:
	T			*_array;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const& copy);
	~Array();
	Array& operator=(Array const& copy);
	unsigned int size() const;
	class OutOfRange : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	T& operator[](unsigned int i);
};

#include "Array.tpp"

#endif