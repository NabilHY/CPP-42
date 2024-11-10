/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:41 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/09 20:23:38 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed {
    private:
        int FixVal;
        static const int literal = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int newVal);
        Fixed(const float newVal);
        Fixed(const Fixed& origin);
        Fixed&  operator =(const Fixed& origin);
        int     getRawBits( void )const;
        int     toInt(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
};

std::ostream& operator << (std::ostream &COUT, const Fixed& ref);
