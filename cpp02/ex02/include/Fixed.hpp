/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:41 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/10 13:37:06 by nhayoun          ###   ########.fr       */
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
        int     getRawBits( void )const;
        int     toInt(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        Fixed&  operator =(const Fixed& origin);
        float   operator *(const Fixed& ref) const;
        float   operator +(const Fixed &ref) const;
        float   operator -(const Fixed &ref) const;
        float   operator /(const Fixed &ref) const;
        bool    operator >(const Fixed &ref) const;
        bool    operator <(const Fixed &ref) const;
        bool    operator >=(const Fixed &ref) const;
        bool    operator <=(const Fixed &ref) const;
        bool    operator ==(const Fixed &ref) const;
        bool    operator !=(const Fixed &ref) const;
        float   operator ++();
        float   operator --();
        float   operator ++(int);
        float   operator --(int);
        static  const   Fixed   &min(const Fixed&, const Fixed&);
        static  const   Fixed   &min(Fixed&, Fixed&);
        static  const   Fixed   &max(const Fixed&, const Fixed&);
        static  const   Fixed   &max(Fixed&, Fixed&);
};

std::ostream& operator << (std::ostream &COUT, const Fixed& ref);

// min 
    // TAKES AS PARAMETERS TWO REFERENCES ON FIXED POINT NUMBERS
        // RETURNS REFERENCE TO THE SMALLEST ONE
    // TAKES AS PARAMETRS TWO REFERECES TO CONSTANT FIXED-NUMBERS