/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:52:43 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/10 16:58:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
    private:
        const *Fixed x;
        const *Fixed y;
    public:
        Point();
        Point(const Fixed &, const Fixed &);
        Point(const float, const float);
        Point(const Point &);
        Fixed &operator =(const Point &);
        ~Point();
};

bool bsp(Point const a, Point const b, Point const point);