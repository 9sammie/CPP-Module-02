/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:25:19 by maballet          #+#    #+#             */
/*   Updated: 2025/12/15 17:19:42 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (): _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

/*
Here the int becomes a fixed-point representation.
since _fractBits is 8, the integer will be shifted on the left by 8 bits.
equivalent to multiply by 256, allowing the value to be stored with a
fixed fractional precision.
*/
Fixed::Fixed ( const int input ): _value(input) {

	std::cout << "Int constructor called" << std::endl;
	_value = input << _fractBits;
}

/*
Here the float becomes a fixed-point representation.
The float is first multiplied by 2^_fractBits (256) to preserve
the fractional precision, then rounded to the nearest integer
using roundf().
This ensures a more accurate conversion from float to fixed-point.

Example:
  input = 42.42
  stored value ≈ roundf(42.42 * 256) = 10860
*/
Fixed::Fixed ( const float input ): _value(input) {

	std::cout << "Float constructor called" << std::endl;
	_value = roundf(input * (1 << _fractBits));
}

Fixed::Fixed ( const Fixed& other ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator = ( const Fixed& other ) {

	std::cout << "Copy assignment operator called" << std::endl;
	if  (this != &other )
		this->_value = other._value;
	return *this;
}

Fixed::~Fixed () {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits () const {

	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits ( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat( void ) const {
	
	return (float)_value / (1 << _fractBits);
}

int Fixed::toInt( void ) const {

	return _value >> _fractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
