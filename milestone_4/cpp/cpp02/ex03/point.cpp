/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:34:59 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/29 21:39:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Point const& src)
{
	this->x = src.x;
	this->y = src.y;
}

Point&	Point::operator=(Point const& rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getx() const{return (this->x);}

Fixed Point::gety() const{return (this->y);}