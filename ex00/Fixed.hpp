/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:18:43 by maballet          #+#    #+#             */
/*   Updated: 2025/12/15 15:51:29 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*
This class defines the canonical form of a C++ class (rule of three ) and it provides:

- A default constructor, to create a new fixed object.
- A copy constructor, to initialize a Fixed object from another one.
- A copy assignment operator, to assign the value of one Fixed object to another existing one.
*/

class Fixed {

	private:
	
	int	_value;
	const static int _fractBits = 8;

	public:

	Fixed ();
	Fixed ( const Fixed& );
	Fixed& operator = ( const Fixed& );
	~Fixed ();
	int getRawBits ( void ) const;
	void setRawBits ( int const raw );
	
};

#endif