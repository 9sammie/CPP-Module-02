/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:25:19 by maballet          #+#    #+#             */
/*   Updated: 2025/12/11 23:39:14 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (): _value(0) {

	std::cout << "Default constructor called" << std::endl;
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
