/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:25:19 by maballet          #+#    #+#             */
/*   Updated: 2026/01/21 17:39:20 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (): _value(0) {}

Fixed::Fixed ( const int input ): _value(input) {

	_value = input << _fractBits;
}

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

Fixed Fixed::operator * ( const Fixed &number ) const {

	Fixed result;
	result.setRawBits((this->_value * number._value) >> this->_fractBits);
	return result;
}

Fixed Fixed::operator / ( const Fixed &number ) const {

	Fixed result;
	result.setRawBits((this->_value << this->_fractBits) / number._value);
	return result;
}

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
