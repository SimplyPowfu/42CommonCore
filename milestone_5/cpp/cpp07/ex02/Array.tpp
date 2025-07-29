/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:40:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/28 17:34:04 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "Default constructor created" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Init default constructor created" << std::endl;
	if (_size)
		_array = new T[_size];
}

template <typename T>
Array<T>::Array(Array const &copy)
{
	std::cout << "Copy Costructor" << std::endl;
	_size = copy.size();
	if (_size)
		_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++){
		_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Distructor called" << std::endl;
	if (_size)
		delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& copy)
{
	if (this != &copy)
	{
		if (_array)
			delete[] _array;
		_array = new T[copy._size];
		_size = copy._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy._array[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size || i < 0)
		throw OutOfRange();
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const { return (_size); }

template <typename T>
const char* Array<T>::OutOfRange::what() const throw() { return("Out of range"); }

#endif