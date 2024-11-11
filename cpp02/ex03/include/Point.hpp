/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:10:04 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/11 15:44:39 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        ~Point();
        Point(const float, const float);
        float getX() const;
        float getY() const;
        // Point(const Point &);
        // Fixed&  operator = (const Fixed &);
};

bool bsp(Point const , Point const , Point const , Point const);

#endif