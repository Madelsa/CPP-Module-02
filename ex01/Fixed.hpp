/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:14:23 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/08/27 15:04:35 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
    int fixedPointNum;
    const static int fractBits = 8;

    public:
    Fixed();
    Fixed(const Fixed &copyTemplate);
    Fixed &operator=(const Fixed &initTemplate);
    Fixed(const int n);
    Fixed(const float n);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif