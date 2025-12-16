/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:25:19 by maballet          #+#    #+#             */
/*   Updated: 2025/12/16 11:47:57 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// We multiply by 2^_fractBits to encode fractional precision into an integer,
// allowing real numbers to be represented using only integer arithmetic.

Fixed::Fixed (): _value(0) {}

/*
Here the int becomes a fixed-point representation.
since _fractBits is 8, the integer will be shifted on the left by 8 bits.
equivalent to multiply by 256, allowing the value to be stored with a
fixed fractional precision.
*/
Fixed::Fixed ( const int input ): _value(input) {

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

the 1 << _fractBits is used because bitshifting doesn't work on a float.
*/
Fixed::Fixed ( const float input ) {

	_value = roundf(input * (1 << _fractBits));
}

Fixed::Fixed ( const Fixed& other ) {

	*this = other;
}

Fixed& Fixed::operator = ( const Fixed& other ) {

	if  (this != &other )
		this->_value = other._value;
	return *this;
}

Fixed::~Fixed () {

}

int Fixed::getRawBits () const {

	return _value;
}

void Fixed::setRawBits ( int const raw ) {

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


// Functions created for this exercice:


bool Fixed::operator < ( const Fixed &number ) const {

	return (this->_value < number._value);
}

bool Fixed::operator > ( const Fixed &number ) const {

	return (this->_value > number._value);
}

bool Fixed::operator <= ( const Fixed &number ) const {

	return (this->_value <= number._value);
}

bool Fixed::operator >= ( const Fixed &number ) const {

	return (this->_value >= number._value);
}

bool Fixed::operator == ( const Fixed &number ) const {

	return (this->_value == number._value);
}

bool Fixed::operator != ( const Fixed &number ) const {

	return (this->_value != number._value);
}

Fixed Fixed::operator + ( const Fixed &number ) const {

	Fixed result;
	result.setRawBits(this->_value + number._value);
	return result;
}

Fixed Fixed::operator - ( const Fixed &number ) const {

	Fixed result;
	result.setRawBits(this->_value - number._value);
	return result;
}

// The >> operator rescales the result of the multiplication by dividing it
// by 2^_fractBits to keep a valid fixed-point representation.

Fixed Fixed::operator * ( const Fixed &number ) const {

	Fixed result;
	result.setRawBits((this->_value * number._value) >> this->_fractBits);
	return result;
}

// Faire un << permet de 

Fixed Fixed::operator / ( const Fixed &number ) const {

	Fixed result;
	result.setRawBits((this->_value << this->_fractBits) / number._value);
	return result;
}

//

Fixed& Fixed::operator ++ () {

	this->_value += 1;
	return *this;
}

Fixed Fixed::operator ++ (int) {

	Fixed temp(*this);
	this->_value += 1;
	return temp;
}

Fixed& Fixed::operator -- () {

	this->_value -= 1;
	return *this;
}

Fixed Fixed::operator -- (int) {

	Fixed temp(*this);
	this->_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a : b);
}
