/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:18:43 by maballet          #+#    #+#             */
/*   Updated: 2025/12/15 17:20:32 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

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
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif