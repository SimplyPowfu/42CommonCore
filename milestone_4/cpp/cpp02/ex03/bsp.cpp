/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:42:33 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/29 21:43:13 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

static float area (const Point p1, const Point p2, const Point p3)
{
	float	area;

	area =	((p1.getx().toFloat() * (p2.gety().toFloat() - p3.gety().toFloat())) +
			(p2.getx().toFloat() * (p3.gety().toFloat() - p1.gety().toFloat())) +
			(p3.getx().toFloat() * (p1.gety().toFloat() - p2.gety().toFloat()))) / 2;
	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d0, d1, d2, d3;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);
	if ( d1 == 0 || d2 == 0 || d3 == 0)
		return (false);
	else if ( d1 + d2 + d3 == d0 )
		return (true);
	return (false);
}