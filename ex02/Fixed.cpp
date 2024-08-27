/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:24:49 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/08/27 18:27:22 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0) {}

Fixed::Fixed(const Fixed &copyTemplate) 
{
    *this = copyTemplate;
}

Fixed &Fixed::operator=(const Fixed &initTemplate) 
{
    if (this != &initTemplate) 
    {
        fixedPointNum = initTemplate.fixedPointNum;
    }
    return *this;
}

Fixed::Fixed(const int n) 
{
    fixedPointNum = n << fractBits;
}

Fixed::Fixed(const float n) 
{
    fixedPointNum = roundf(n * (1 << fractBits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const 
{
    return fixedPointNum;
}

void Fixed::setRawBits(int const raw) 
{
    fixedPointNum = raw;
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(fixedPointNum) / (1 << fractBits);
}

int Fixed::toInt(void) const 
{
    return fixedPointNum >> fractBits;
}

bool Fixed::operator>(const Fixed &other) const 
{
    return fixedPointNum > other.fixedPointNum;
}

bool Fixed::operator<(const Fixed &other) const 
{
    return fixedPointNum < other.fixedPointNum;
}

bool Fixed::operator>=(const Fixed &other) const 
{
    return fixedPointNum >= other.fixedPointNum;
}

bool Fixed::operator<=(const Fixed &other) const 
{
    return fixedPointNum <= other.fixedPointNum;
}

bool Fixed::operator==(const Fixed &other) const 
{
    return fixedPointNum == other.fixedPointNum;
}

bool Fixed::operator!=(const Fixed &other) const 
{
    return fixedPointNum != other.fixedPointNum;
}

Fixed   Fixed::operator+( const Fixed &other ) const {
    return Fixed( this->toFloat() + other.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &other ) const {
    return Fixed( this->toFloat() - other.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &other ) const {
    return Fixed( this->toFloat() * other.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &other ) const {
    return Fixed( this->toFloat() / other.toFloat() );
}


Fixed& Fixed::operator++() 
{
    ++fixedPointNum;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    ++fixedPointNum;
    return temp;
}

Fixed& Fixed::operator--() 
{
    --fixedPointNum;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    --fixedPointNum;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return (out);
}
