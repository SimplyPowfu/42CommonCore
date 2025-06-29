/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:17:34 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/29 19:25:33 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0)
{
	std::cout << "Default costructor called" << std::endl;
}

Fixed::Fixed(const int parameter)
{
	std::cout << "Int costructor called" << std::endl;
    _fixedPointNumber = parameter << _factionalBits;
}

Fixed::Fixed(const float floatParam)
{
	std::cout << "Float costructor called" << std::endl;
    _fixedPointNumber = roundf(floatParam * (1 << _factionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) 
        this->_fixedPointNumber = copy.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float   Fixed::toFloat( void ) const
{
    return static_cast<float>(_fixedPointNumber) / (1 << _factionalBits);
}

int		Fixed::toInt( void ) const
{
    return _fixedPointNumber >> _factionalBits;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNumber;
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointNumber = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}