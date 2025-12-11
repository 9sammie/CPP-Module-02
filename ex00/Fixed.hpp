/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:18:43 by maballet          #+#    #+#             */
/*   Updated: 2025/12/11 23:39:59 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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