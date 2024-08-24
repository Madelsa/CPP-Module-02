/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:24:49 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/08/24 13:07:42 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyTemplate)
{
    std::cout << "Copy constructor called" << std::endl;
    fixedPointNum = copyTemplate.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &initTemplate)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &initTemplate)
        this->fixedPointNum = initTemplate.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw )
{
   fixedPointNum = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointNum);
}