/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 12:39:40 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : N(n)
{
	std::cout << "Costructor created" << std::endl;
}

Span::Span(Span const& copy)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

Span::~Span()
{
	std::cout << "Distructor called" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

void Span::addNumber(int n)
{
	if (v.size() >= N)
		throw Span::FullStore();
	v.insert(std::lower_bound(v.begin(), v.end(), n), n);
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2)
		throw Span::NotEnoughNumbers();
	return v[v.size() - 1] - v[0];
}

unsigned int Span::shortestSpan()
{
	if (v.size() < 2)
		throw Span::NotEnoughNumbers();
	unsigned int i = 0;
	unsigned int j = 1;
	unsigned int size = v.size();
	unsigned int currentSpan = std::abs(v[j] - v[i]);
	while (j < size)
	{
		if (static_cast<unsigned int>(std::abs(v[j] - v[i])) < currentSpan)
			currentSpan = v[j] - v[i];
		i++;
		j++;
	}
	return (currentSpan);
}

void Span::addRange(int first, int last)
{
	if (first >= last)
		return;
	if (v.size() >= N)
		throw Span::FullStore();
	while (first <= last)
	{
		v.insert(std::lower_bound(v.begin(), v.end(), first), first);
		first++;
		if (v.size() >= N)
		throw Span::FullStore();
	}
}

const char* Span::FullStore::what() const throw()
{
	return ("The container is already full");
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return ("Not enough numbers to compute the span");
}