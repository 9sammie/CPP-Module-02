/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:40:36 by maballet          #+#    #+#             */
/*   Updated: 2026/01/21 13:07:54 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main() {

    std::cout << GREYBG << "=== CONSTRUCTEURS ===" << STD << std::endl << std::endl;
    Fixed a;
    Fixed b(42);
    Fixed c(42.42f);
    Fixed d(b);
    std::cout << GREEN << "a = " << a << STD << "\n" << GREEN << "b = " << b << STD << "\n" << GREEN << "c = " << c << STD << "\n" << GREEN << "d = " << d << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== OPÉRATEURS D'AFFECTATION ===" << STD << std::endl << std::endl;
    a = Fixed(10.5f);
    std::cout << GREEN << "a après a = Fixed(10.5f) : " << a << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== OPÉRATEURS ARITHMÉTIQUES ===" << STD << std::endl << std::endl;
    Fixed e = b + c;
    Fixed f = c - b;
    Fixed g = b * c;
    Fixed h = c / b;
    std::cout << GREEN << "b + c = " << e << STD << std::endl;
    std::cout << GREEN << "c - b = " << f << STD << std::endl;
    std::cout << GREEN << "b * c = " << g << STD << std::endl;
    std::cout << GREEN << "c / b = " << h << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== OPÉRATEURS DE COMPARAISON ===" << STD << std::endl << std::endl;
    std::cout << GREEN << "b < c : " << (b < c) << STD << std::endl;
    std::cout << GREEN << "b > c : " << (b > c) << STD << std::endl;
    std::cout << GREEN << "b <= d : " << (b <= d) << STD << std::endl;
    std::cout << GREEN << "b >= d : " << (b >= d) << STD << std::endl;
    std::cout << GREEN << "b == d : " << (b == d) << STD << std::endl;
    std::cout << GREEN << "b != c : " << (b != c) << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== INCRÉMENTATION / DÉCRÉMENTATION ===" << STD << std::endl << std::endl;
    Fixed i;
    std::cout << GREEN << "i = " << i << STD << std::endl;
    std::cout << GREEN << "++i = " << ++i << STD << std::endl;
    std::cout << GREEN << "i++ = " << i++ << STD << std::endl;
    std::cout << GREEN << "i après i++ = " << i << STD << std::endl;
    std::cout << GREEN << "--i = " << --i << STD << std::endl;
    std::cout << GREEN << "i-- = " << i-- << STD << std::endl;
    std::cout << GREEN << "i après i-- = " << i << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== MIN / MAX ===" << STD << std::endl << std::endl;
    Fixed j(5.5f);
    Fixed k(10.1f);
    std::cout << GREEN << "min(j, k) = " << Fixed::min(j, k) << STD << std::endl;
    std::cout << GREEN << "max(j, k) = " << Fixed::max(j, k) << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== MIN / MAX CONST ===" << STD << std::endl << std::endl;
    const Fixed l(2.2f);
    const Fixed m(3.3f);
    std::cout << GREEN << "min(l, m) = " << Fixed::min(l, m) << STD << std::endl;
    std::cout << GREEN << "max(l, m) = " << Fixed::max(l, m) << STD << std::endl;

    std::cout << std::endl << std::endl << GREYBG << "=== CONVERSIONS ===" << STD << std::endl << std::endl;
    std::cout << GREEN << "b.toInt() = " << b.toInt() << STD << std::endl;
    std::cout << GREEN << "c.toFloat() = " << c.toFloat() << STD << std::endl;

    return 0;
}
