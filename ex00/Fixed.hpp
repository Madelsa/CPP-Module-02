/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:14:23 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/08/24 12:25:40 by mabdelsa         ###   ########.fr       */
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
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif