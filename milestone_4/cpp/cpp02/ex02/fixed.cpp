/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:17:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/29 20:44:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {}

Fixed::Fixed(const int parameter)
{
    _fixedPointNumber = parameter << _factionalBits;
}

Fixed::Fixed(const float floatParam)
{
    _fixedPointNumber = roundf(floatParam * (1 << _factionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) 
{
    if (this != &copy) 
        this->_fixedPointNumber = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed() {}

float   Fixed::toFloat( void ) const
{
    return (static_cast<float>(_fixedPointNumber) / static_cast<float>(1 << _factionalBits));
}

int		Fixed::toInt( void ) const
{
    return (_fixedPointNumber >> _factionalBits);
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointNumber = raw;
}

bool	Fixed::operator>(const Fixed &copy) const
{
    return (_fixedPointNumber > copy._fixedPointNumber);
}

bool	Fixed::operator<(const Fixed &copy) const
{
    return (_fixedPointNumber < copy._fixedPointNumber);
}

bool	Fixed::operator>=(const Fixed &copy) const
{
    return (_fixedPointNumber >= copy._fixedPointNumber);
}

bool	Fixed::operator<=(const Fixed &copy) const
{
    return (_fixedPointNumber <= copy._fixedPointNumber);
}

bool	Fixed::operator==(const Fixed &copy) const
{
    return (_fixedPointNumber == copy._fixedPointNumber);
}

bool	Fixed::operator!=(const Fixed &copy) const
{
    return (_fixedPointNumber != copy._fixedPointNumber);
}

Fixed	Fixed::operator+(const Fixed &copy) const
{
   return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
    return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
    return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
    return (Fixed(this->toFloat() / copy.toFloat()));
}

Fixed &Fixed::operator++()
{
    _fixedPointNumber++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return (temp);
}

Fixed &Fixed::operator--()
{
    _fixedPointNumber--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return (out);
}