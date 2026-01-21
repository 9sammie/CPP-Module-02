/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:18:43 by maballet          #+#    #+#             */
/*   Updated: 2026/01/21 17:37:17 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define STD			"\033[0m"
#define GREEN		"\033[38;5;34m\033[48;5;193m"
#define GREYBGBOLD	"\033[48;5;237m\033[1m"

# include <iostream>
# include <cmath>

#define true 1
#define false 0

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
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif