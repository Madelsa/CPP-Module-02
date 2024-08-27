/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:24:49 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/08/27 16:05:36 by mahmoud          ###   ########.fr       */
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
    *this = copyTemplate;
}

Fixed& Fixed::operator=(const Fixed &initTemplate)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &initTemplate)
        this->fixedPointNum = initTemplate.fixedPointNum;
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

Fixed::Fixed(const int n) 
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointNum = n << fractBits;
}

Fixed::Fixed(const float n) 
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointNum = roundf(n * (1 << fractBits));
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(fixedPointNum) / (1 << fractBits);
}

int Fixed::toInt(void) const 
{
    return (fixedPointNum >> fractBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return (out);
}
