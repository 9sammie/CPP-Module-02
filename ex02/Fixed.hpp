/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:18:43 by maballet          #+#    #+#             */
/*   Updated: 2025/12/16 11:40:34 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

#define true 1
#define false 0

/*
This class introduces the notion of a controlled type conversion.
*/
class Fixed {

	private:
	
	int	_value;
	const static int _fractBits = 8;

	public:

	Fixed ();
	Fixed ( const int input );
	Fixed ( const float input );
	Fixed ( const Fixed& );
	Fixed& operator = ( const Fixed& );
	~Fixed ();
	
	int getRawBits ( void ) const;
	void setRawBits ( int const raw );
	
	float toFloat ( void ) const;
	int toInt( void ) const;
	
	bool operator < ( const Fixed &number ) const;
	bool operator > ( const Fixed &number ) const;
	bool operator <= ( const Fixed &number ) const;
	bool operator >= ( const Fixed &number ) const;
	bool operator == ( const Fixed &number ) const;
	bool operator != ( const Fixed &number ) const;
	Fixed operator + ( const Fixed &number ) const;
	Fixed operator - ( const Fixed &number ) const;
	Fixed operator * ( const Fixed &number ) const;
	Fixed operator / ( const Fixed &number ) const;
	Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);
	Fixed& min(Fixed& a, Fixed& b);
	Fixed& max(Fixed& a, Fixed& b);
	const Fixed& min(const Fixed& a, const Fixed& b);
	const Fixed& max(const Fixed& a, const Fixed& b);
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif