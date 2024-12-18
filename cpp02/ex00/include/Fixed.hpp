/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:41 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/11 13:47:06 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int FixVal;
        static const int literal = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& origin);
        Fixed& operator =(const Fixed& origin);
        int     getRawBits( void )const;
        void    setRawBits(int const raw);
};

#endif